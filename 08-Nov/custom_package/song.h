#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 

typedef bool(*Comparator)(const Song &,const Song &);
//  you *MIGHT* have to change the declaration of pq1 and pq2

bool compare_ATC(const Song &s1,const Song &s2){
  if (s1.artist > s2.artist) {
    return true;
  }
  if (s1.artist == s2.artist && s1.title > s2.title) {
      return true;
  }
  if (s1.artist == s2.artist && s1.title == s2.title && s1.count > s2.count) {
      return true;
  }
  return false;
}

bool compare_CAT(const Song &s1,const Song &s2){
  if (s1.count < s2.count) {
    return true;
  }
  if (s1.count == s2.count && s1.artist > s2.artist) {
      return true;
  }
  if (s1.count == s2.count && s1.artist == s2.artist && s1.title > s2.title) {
      return true;
  }
  return false;
}

CP::priority_queue<Song, Comparator> pq1(compare_ATC);
CP::priority_queue<Song, Comparator> pq2(compare_CAT);

#endif
