#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=h082 (2. 贏家預測)

typedef long long LL;

struct Person {
    LL s;
    LL t;
    int i;
    int loss;

    Person(LL s = 0, LL t = 0, int i = 0, int loss = 0)
    : s(s), t(t), i(i), loss(loss) {};
};

int n, m;
vector<Person> people;
vector<int> index_vec;

void read_input();
int find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    cout << find_ans();
}

void read_input() 
{
    cin >> n >> m;
    vector<Person> temp_people(n);
    
    for (int i = 0; i < n; ++i) cin >> temp_people[i].s;
    for (int i = 0; i < n; ++i) cin >> temp_people[i].t;
    for (int i = 0; i < n; ++i) temp_people[i].i = i + 1;

    int idx;

    for (int i = 0; i < n; ++i) {
        cin >> idx;
        people.push_back(move(temp_people[idx - 1]));
    }
}

int find_ans() 
{
    vector<Person> winner;
    vector<Person> loser;

    while (people.size() > 1) {

        winner.clear();
        loser.clear();

        for (int i = 0, size = people.size(); i < size; i += 2) {

            if (i == size - 1) {
                winner.push_back(people[i]);
                continue;
            }

            LL  a = people[i].s, 
                b = people[i].t, 
                c = people[i + 1].s, 
                d = people[i + 1].t;

            int win = 0, lose = 0;

            if (a * b >= c * d) {
                people[i].s += (c * d) / (2 * b);
                people[i].t += (c * d) / (2 * a); 
                people[i + 1].s += c / 2;
                people[i + 1].t += d / 2; 
                win = i, lose = i + 1;
            }
            else {
                people[i].s += a / 2;
                people[i].t += b / 2;
                people[i + 1].s += (a * b) / (2 * d);
                people[i + 1].t += (a * b) / (2 * c); 
                win = i + 1, lose = i;
            }

            if (people[lose].loss + 1 < m) {
                people[lose].loss ++;
                loser.push_back(people[lose]);
            }
            winner.push_back(people[win]);
        }

        people = winner;
        people.insert(
            people.end(), 
            loser.begin(), 
            loser.end()
        );
    }

    return people[0].i;
}