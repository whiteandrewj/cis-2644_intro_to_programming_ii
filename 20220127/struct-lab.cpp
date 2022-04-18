#include <iostream>
#include <vector>
using namespace std;

struct MovieData {
    string title;
    string director;
    int yearReleased;
    int runningTime;

    void display(MovieData m) {
        cout << m.title << ". Directed by " << m.director << ". Released " << m.yearReleased << ". " << m.runningTime << " min." << endl;
    }
};

int main() {
    MovieData m1;
    m1.title = "The Fellowship of the Ring";
    m1.director = "Peter Jackson";
    m1.yearReleased = 2001;
    m1.runningTime = 178;
    MovieData m2;
    m2.title = "The Matrix";
    m2.director = "The Wachowskis";
    m2.yearReleased = 1999;
    m2.runningTime = 136;

    vector<MovieData> movies;
    movies.push_back(m1);
    movies.push_back(m2);

    for (MovieData m : movies) {
        m.display(m);
    }

    return 0;
}