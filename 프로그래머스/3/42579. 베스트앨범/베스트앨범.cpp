#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Music {
    int idx;
    int play;
    string genre;
    
    Music(int idx, int play, string genre) : idx(idx), play(play), genre(genre) {}
    
    bool operator < (const Music& ref) const {
        if (genre != ref.genre)
            return genre < ref.genre;
        if (play != ref.play)
            return play > ref.play;
        else return idx < ref.idx;
    };
};

struct Genre {
    string genre;
    int play;
    vector<Music> musics;
    
    Genre(string genre) : genre(genre) {
        play = 0;
    }
    
    bool operator < (const Genre& ref) const {
        return play > ref.play;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    int N = genres.size();
    vector<Music> mlst;
    
    for (int i=0; i<N; i++) {
        Music m = Music(i, plays[i], genres[i]);
        mlst.push_back(m);
    }
    sort(mlst.begin(), mlst.end());
    
    vector<Genre> glst;
    string prev = "";
    int gp = -1;
    
    for (Music m : mlst) {
        if (m.genre != prev) {
            Genre g = Genre(m.genre);
            glst.push_back(g);
            prev = m.genre;
            gp++;
        }
        glst[gp].play += m.play;
        glst[gp].musics.push_back(m);
    }
    sort(glst.begin(), glst.end());
    
    vector<int> answer;
    for (Genre g : glst) {
        sort(g.musics.begin(), g.musics.end());
        answer.push_back(g.musics[0].idx);
        if (g.musics.size() > 1)
            answer.push_back(g.musics[1].idx);
    }
    
    return answer;
}