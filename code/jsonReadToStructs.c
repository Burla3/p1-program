#include "jsonReadToStructs.h"

void populateStudyStructFromConfig(json_t *rootConfig, Study *studyArray)
{
  /* root->groups[] */
  json_t *groups = json_object_get(rootConfig, "groups");

  int groupsIndex;
  json_t *groupsValue;

  /* root->groups[i] */
  json_array_foreach(groups, groupsIndex, groupsValue) {
    /* root->groups[i]->course_id[] */
    json_t *course_ids = json_object_get(groupsValue, "course_id");
    /* root->groups[i]->students[] */
    json_t *students = json_object_get(groupsValue, "students");
    /* root->groups[i]->name */
    json_t *groupsName = json_object_get(groupsValue, "name");

    int numberOfStudents = json_array_size(students);
    int numberOfCourses = json_array_size(course_ids);
    int totalNumberOfLectures = 0;
    const char *tempName = json_string_value(groupsName);
    char *name = (char*) malloc(5 * sizeof(char));
    strcpy(name, tempName);

    Course *studyCourse = (Course*) malloc(numberOfCourses * sizeof(Course));

    Study newStudy = {name, studyCourse, numberOfCourses, 0};

    studyArray[groupsIndex] = newStudy;

    int courseIdIndex;
    json_t *courseIdValue;

    /* root->groups[i]->course_id[i] */
    json_array_foreach(course_ids, courseIdIndex, courseIdValue) {

      /* root->courses[] */
      json_t *courses = json_object_get(rootConfig, "courses");

      int coursesIndex;
      json_t *coursesValue;

      /* root->courses[i] */
      json_array_foreach(courses, coursesIndex, coursesValue) {
        /* root->courses[i]->id */
        json_t *course_id = json_object_get(coursesValue, "id");

        if (json_integer_value(courseIdValue) == json_integer_value(course_id)) {

          /* Sloppy malloc with total number of rooms instead of actual number of rooms */

          char **availableRooms = (char**) malloc(getTotalNumberOfRooms(rootConfig) * sizeof(char*));

          int numberOfRooms = 0;

          /* root->courses[i]->name */
          json_t *course_name = json_object_get(coursesValue, "name");

          json_t *coursesLectures = json_object_get(coursesValue, "lectures");

          int coursesLecturesIndex;
          json_t *coursesLecturesValue;

          /* root->courses[i]->lectures[i] */
          json_array_foreach(coursesLectures, coursesLecturesIndex, coursesLecturesValue) {

            totalNumberOfLectures++;

            /* root->courses[i]->lectures[i]->roomType */
            json_t *lectureRoom = json_object_get(coursesLecturesValue, "roomType");

            /* root->rooms{} */
            json_t *rooms = json_object_get(rootConfig, "rooms");

            /* root->rooms{}->(eg. AUDITORIUM)[] */
            json_t *roomsType = json_object_get(rooms, json_string_value(lectureRoom));

            int roomsRoomTypeIndex;
            json_t *roomsRoomTypeValue;

            /* root->rooms{}->(eg. AUDITORIUM)[i] */
            json_array_foreach(roomsType, roomsRoomTypeIndex, roomsRoomTypeValue) {

              /* root->rooms{}->(eg. AUDITORIUM)[i]->capacity */
              json_t *roomsTypeCapacity = json_object_get(roomsRoomTypeValue, "capacity");

              /* There is capacity for all students in the room */
              if (json_integer_value(roomsTypeCapacity) >= numberOfStudents) {

                /* root->rooms{}->(eg. AUDITORIUM)[i]->name */
                json_t *roomsTypeName = json_object_get(roomsRoomTypeValue, "name");
                const char *roomTypeName = json_string_value(roomsTypeName);

                char *roomName = (char*) malloc(10 * sizeof(char));
                strcpy(roomName, roomTypeName);

                int j, insert = 1;

                availableRooms[numberOfRooms] = (char*) malloc(10 * sizeof(char));

                if (numberOfRooms == 0) {
                  insert = 0;
                  strcpy(availableRooms[numberOfRooms], roomName);
                  numberOfRooms++;
                } else {
                  for (j = 0; j < numberOfRooms; j++) {
                    if (strcmp(availableRooms[j], roomName) == 0) {
                      insert = 0;
                      break;
                    }
                  }
                }
                if (insert) {
                  strcpy(availableRooms[numberOfRooms], roomName);
                  numberOfRooms++;
                }
              }
            }
          }
          const char *tempNameCourse = json_string_value(course_name);
          char *nameCourse = (char*) malloc(5 * sizeof(char));
          strcpy(nameCourse, tempNameCourse);

          Course newCourse = {nameCourse, json_array_size(coursesLectures), availableRooms, numberOfRooms};
          studyArray[groupsIndex].studyCourses[courseIdIndex] = newCourse;
          studyArray[groupsIndex].totalNumberOfLectures = totalNumberOfLectures;
        }
      }
    }
  }
}

int hasCourseId(json_t *array, int id) {
  size_t index;
  json_t *value;

  json_array_foreach(array, index, value) {
    if (id == json_integer_value(value)) {
      return 1;
    }
  }
  return 0;
}

void printStudyStruct(Study study)
{
  int i, j;

  printf("Study: %s\tNumber of courses: %d\tTotal number of lectures: %d\n", study.name, study.numberOfCourses, study.totalNumberOfLectures);

  for (i = 0; i < study.numberOfCourses; i++)
  {
    printf("\tCourse name: %s\tNumber of lectures: %d\tNumber of rooms: %d\n", study.studyCourses[i].course,
      study.studyCourses[i].numberOfLectures, study.studyCourses[i].numberOfRooms);
    for (j = 0; j < study.studyCourses[i].numberOfRooms; j++)
    {
      printf("\t\tRoom: %s\n", study.studyCourses[i].rooms[j]);
    }
  }
}

int getTotalNumberOfRooms(json_t *rootConfig)
{
  int numberOfRooms = 0;

  json_t *rooms, *roomsType;

  /* root->rooms{} */
  rooms = json_object_get(rootConfig, "rooms");

  /* root->rooms{}->AUDITORIUM[] */
  roomsType = json_object_get(rooms, "AUDITORIUM");
  numberOfRooms += json_array_size(roomsType);
  /* root->rooms{}->SEMINAR_ROOM[] */
  roomsType = json_object_get(rooms, "SEMINAR_ROOM");
  numberOfRooms += json_array_size(roomsType);
  /* root->rooms{}->GROUPROOM[] */
  roomsType = json_object_get(rooms, "GROUPROOM");
  numberOfRooms += json_array_size(roomsType);

  return numberOfRooms;
}
