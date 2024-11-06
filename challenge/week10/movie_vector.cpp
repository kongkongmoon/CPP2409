#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie {
private:
    string title;
    double rating;

public:
    // 생성자
    Movie(string t = "", double r = 0.0) : title(t), rating(r) {}

    // 영화 정보를 출력하는 메서드
    void PrintMovie() const {
        cout << title << ": " << rating << endl;
    }
};

int main() {
    vector<Movie> movies;

    // 영화 객체를 벡터에 추가
    movies.push_back(Movie("Titanic", 9.9));
    movies.push_back(Movie("Gone with the Wind", 9.6));
    movies.push_back(Movie("Terminator", 9.7));

    // 모든 영화 정보를 출력
    for (const auto& e : movies) {
        e.PrintMovie();
    }

    return 0;
}
