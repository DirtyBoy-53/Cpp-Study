#include <iostream>
#include <queue>

struct student
{
    std::string name;
    int score;
};

struct cmp
{
    bool operator()(const student& a,const student& b) const {
        return a.score < b.score || (a.score == b.score && a.name > b.name);
    }
};

std::priority_queue<student,std::vector<student>,cmp> pq;

int main(){
    int n;
    std::cin >> n;
    for(int i = 1;i <= n; i++){
        std::string name;
        int score;
        std::cin >> name >> score;
        pq.push({name,score});
    }
    student rk1 = pq.top();
    std::cout << rk1.name << " " << rk1.score << std::endl;
    return 0;
}
