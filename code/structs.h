#define POPULATION_SIZE 10000

#ifndef STUDYNAME
#define STUDYNAME
  typedef enum StudyName {
    DAT, MAT
  } StudyName;
#endif

#ifndef LECTURE
#define LECTURE
  typedef struct Lecture {
    char *type;
    char *room;
  } Lecture;
#endif

#ifndef TIMETABLE
#define TIMETABLE
  typedef struct Timetable {
    StudyName studyName;
    int numberOfLectures;
    Lecture *lectures;
  } Timetable;
#endif

#ifndef POPMEMBER
#define POPMEMBER
  typedef struct PopMember {
    int fitnessScore;
    Timetable *studies;
  } PopMember;
#endif

#ifndef COURSE
#define COURSE
  typedef struct Course {
    char course[5];
    int numberOfLectures;
    char **rooms;
    int numberOfRooms;
  } Course;
#endif

#ifndef STUDY
#define STUDY
  typedef struct Study {
    char name[15];
    Course *studyCourses;
    int numberOfCourses;
    int totalNumberOfLectures;
  } Study;
#endif