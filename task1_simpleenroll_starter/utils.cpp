/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 * Please complete each STUDENT TODO in this file.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

// (FIRST) STUDENT TODO: change how variables are passed into the functions you
// must complete

#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <tuple>
#include <vector>

// STUDENT TODO: add paths
std::string COURSES_OFFERED_CSV_PATH = "student_output//courses_offered.csv";

std::string COURSES_NOT_OFFERED_CSV_PATH = "student_output//courses_not_offered.csv";

struct Course {
  std::string title;
  std::string number_of_units;
  std::string quarter;

  // ignore this!
  bool operator==(const Course &other) const {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

// forward declarations
void delete_elem_from_vector(std::vector<Course> &v, Course &elem);
std::vector<std::string> split(std::string s, char delim);

/*
 * This function should populate the vector_of_courses with structs of type
 * Class We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 */
void parse_csv(std::string filename, std::vector<Course> &vector_of_courses) {
  std::ifstream ifs(filename);
  if(ifs.is_open()) {
    std::string line;
    //第一行的数据丢掉
    std::getline(ifs, line);
    //test 是否存入
    //std::cout << line << std::endl;
    while(std::getline(ifs, line)) { //getline为获得字符时返回空?????i++不行 getline行？？？？
      //存入结构体 向量
      std::vector<std::string> data;
      data = split(line, ',');
      //std::cout << data[0] << "..." << data[1] << "..." << data[2] << std::endl;
      Course course;
      course.title = data[0];
      course.number_of_units = data[1];
      course.quarter = data[2];
      //std::cout << course.title << course.number_of_units << course.quarter << std::endl;
      vector_of_courses.push_back(course);
      //std::cout << vector_of_courses[i].title << vector_of_courses[i].number_of_units << vector_of_courses[i].quarter << std::endl;
    }
    ifs.close();
    //std::cout << vector_of_courses[0].title << vector_of_courses[0].number_of_units << vector_of_courses[0].quarter << std::endl;
  }
}

/*
 * This function has TWO requirements.
 * 1) Write the courses that are offered to the file courses_offered.csv inside
 * the student_output folder
 *
 * 2) Delete classes that are offered from vector_of_courses.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 */
void write_courses_offered(std::vector<Course> &vector_of_courses) {
  //write out to the file
  std::ofstream ofs(COURSES_OFFERED_CSV_PATH);
  for (int i = 0; i < vector_of_courses.size(); i++)
  {
    std::string quarter = vector_of_courses[i].quarter;
    //c_str()将string转换为const char*
    if(strcmp(quarter.c_str(), "null") != 0) {
      if(ofs.is_open()) {
        ofs << vector_of_courses[i].title << "," << vector_of_courses[i].number_of_units << "," << quarter << "\n";
      }
    }
  }
  ofs.close();
  
  //delete 循环一次不行，会删错
  int flag = 0;
  int max_size = vector_of_courses.size();
  for(int i = 0; i < max_size; i++) { //最多循环初始size次
    for(int j = 0; j < vector_of_courses.size(); j++) {
      std::string quarter = vector_of_courses[j].quarter;
      //c_str()将string转换为const char*
      if(strcmp(quarter.c_str(), "null") != 0) {
        delete_elem_from_vector(vector_of_courses, vector_of_courses[j]);
        flag = 1; //找到null 删除并重新循环
        break;
      }
    }
    if(flag == 0) { //没有null了 退出循环
      break;
    }
  }
  //test
  /*
  for (int i = 0; i < vector_of_courses.size(); i++)
  {
    std::cout << vector_of_courses[i].title << vector_of_courses[i].number_of_units << vector_of_courses[i].quarter << std::endl;
  }
  */
}

/*
 * This function writes the courses NOT offered to the file
 * courses_not_offered.csv inside of the student_output folder
 *
 * This function is ALWAYS called after the write_courses_offered function.
 * vector_of_courses will trivially contain classes that are not offered
 * since you delete offered classes from vector_of_courses in the
 * 'write_courses_offered' function.
 *
 * HINT: This should be VERY similar to write_courses_offered
 */
void write_courses_not_offered(std::vector<Course> &vector_of_courses) {
  //write out to the file
  std::ofstream ofs(COURSES_NOT_OFFERED_CSV_PATH);
  for (int i = 0; i < vector_of_courses.size(); i++)
  {
    if(ofs.is_open()) {
      ofs << vector_of_courses[i].title << "," << vector_of_courses[i].number_of_units << "," << vector_of_courses[i].quarter << "\n";
    } 
  }
  ofs.close();
}

/* ######## HEYA! DON'T MODIFY ANYTHING BEYOND THIS POINT THX ######## */

// TODO: ADD DOCUMENTATION COMMENTS
void print_vector(std::vector<Course> vector_of_courses) {
  for (int i = 1; i < vector_of_courses.size(); ++i) {
    std::cout << vector_of_courses[i].title << ","
              << vector_of_courses[i].number_of_units << ","
              << vector_of_courses[i].quarter << std::endl;
  }
}

void delete_elem_from_vector(std::vector<Course> &v, Course &elem) {
  auto it = std::find(v.begin(), v.end(), elem);
  v.erase(it);
}

std::vector<std::string> split(std::string s, char delim) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (getline(ss, token, ',')) {
    return_vec.push_back(token);
  }
  return return_vec;
}
