#define POPULATION_SIZE 10000

#ifndef STUDYNAME
#define STUDYNAME
  enum studyName {
    Dat, Mat
  };
#endif

#ifndef LECTURE
#define LECTURE
  typedef struct lecture {
    char *type;
    char *room;
  } lecture;
#endif

#ifndef TIMETABLE
#define TIMETABLE
  typedef struct timetable {
    enum studyName studyName;
    int numberOfLectures;
    lecture *lectures;
  } timetable;
#endif

#ifndef POPMEMBER
#define POPMEMBER
  typedef struct popMember {
    int fitnessScore;
    timetable *studies;
  } popMember;
#endif

#ifndef COURSE
#define COURSE
  typedef struct course {
    char *course;
    int lectures;
  } course;
#endif