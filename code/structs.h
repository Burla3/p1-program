#define POPULATION_SIZE 2
#define PENALTY_HARD 100
#define PENALTY_SOFT 1
#define DAYS_IN_SEMESTER 120
#define MUTATION_RATE 3
#define MAX_GENERATIONS 20

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
    char *studyName;
    int numberOfLectures;
    Lecture *lectures;
  } Timetable;
#endif

#ifndef POPMEMBER
#define POPMEMBER
  typedef struct PopMember {
    int fitnessScore;
    int numberOfStudies;
    Timetable *studies;
  } PopMember;
#endif

#ifndef COURSE
#define COURSE
  typedef struct Course {
    char *course;
    int numberOfLectures;
    char **rooms;
    int numberOfRooms;
  } Course;
#endif

#ifndef STUDY
#define STUDY
  typedef struct Study {
    char *name;
    Course *studyCourses;
    int numberOfCourses;
    int totalNumberOfLectures;
  } Study;
#endif

#ifndef CALENDERDATA
#define CALENDERDATA
  typedef struct CalenderData {
    double lectureTimeStart;
    int day;
    int month;
    char *type;
    char *room;
  } CalenderData;
#endif

#ifndef TIMETABLEWITHDATES
#define TIMETABLEWITHDATES
  typedef struct TimetableWithDates {
    Lecture lecture;
    CalenderData calender;
  } TimetableWithDates;
#endif
