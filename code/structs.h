#define POPULATION_SIZE 1
#define PENALTY_HARD 100
#define PENALTY_SOFT 1
#define DAYS_IN_SEMESTER 120

#ifndef LECTURE
#define LECTURE
  typedef struct Lecture {
    char type[5];
    char room[100];
  } Lecture;
#endif

#ifndef TIMETABLE
#define TIMETABLE
  typedef struct Timetable {
    char studyName[15];
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

#ifndef CALENDERDATA
#define CALENDERDATA
  typedef struct CalenderData {
    double lectureTimeStart;
    int day;
    int month;
  } CalenderData;
#endif

#ifndef TIMETABLEWITHDATES
#define TIMETABLEWITHDATES
  typedef struct TimetableWithDates {
    Lecture lecture;
    CalenderData calender;
  } TimetableWithDates;
#endif

