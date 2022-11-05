#include <vector>
#include <iostream>
using namespace std;

const int Max_N = 105;
const int Max_L = 105;

int N, M, T, L, S;
int cardQue[Max_N * Max_L], mp[Max_N * Max_L], qc;
int cnt[Max_N * Max_L];
vector<int> que;

struct person_t {
    int pos;
    vector<int> card;

    void reset(int l) {
       
    }

    void change() {
        for (size_t i = 0; i < card.size(); i++)
            card[i] = lower_bound(cardQue + 1, cardQue + 1 + qc, card[i]) - cardQue;

        for (size_t i = 0; i < card.size(); i++)
            cout << card[i];
    }

    void retrieve(int l) {
        for (size_t i = l; i < que.size(); i++) {
            card.push_back(que[i]);
            --cnt[que[i]];
        }
        que.resize(l);
    }

    void put(int round) {
        if (pos < 0)
            return;
        int curCard = card[pos++];
        que.push_back(curCard);
        ++cnt[curCard];
        if (curCard == S && que.size() > 1) {
            retrieve(0);
        } else if (cnt[curCard] >= 2) {
            size_t p = que.size() - 2;
            while (p > 0 && que[p] != curCard) --p;
            retrieve(p);
        }
        if (pos >= (int)card.size())
            pos = -round;
    }

    int get_cnt() { return pos < 0 ? pos : card.size() - pos; }

    void display_card() {
        if (pos < 0) {
            puts("");
        } else {
            for (size_t i = pos; i < card.size(); i++)
                printf("%d%c", mp[card[i]], " \n"[i + 1 == card.size()]);
        }
    }
} player[Max_N];

int main() {
    while (scanf("%d%d%d%d%d", &N, &M, &L, &S, &T), (N != -1 || M != -1 || L != -1 || S != -1 || T != -1)) {
        qc = 0;
        for (int i = 1; i <= N; i++) player[i].reset(L);
        cardQue[++qc] = S;
        sort(cardQue + 1, cardQue + 1 + qc);
        qc = unique(cardQue + 1, cardQue + 1 + qc) - cardQue - 1;
        for (int i = 1; i <= qc; i++) mp[i] = cardQue[i];
        S = lower_bound(cardQue + 1, cardQue + 1 + qc, S) - cardQue;
        for (int i = 1; i <= N; i++) player[i].change();



        que.clear();
        for (int i = 1; i <= qc; i++) cnt[i] = 0;
        for (int r = 1; r <= T; r++) {
            for (int i = 1; i <= N; i++) player[i].put(r);
            int c = 0;
            for (int i = 1; i <= N; i++) c += player[i].get_cnt() > 0;
            if (c <= 1)
                break;
        }

        for (int i = 1; i <= N; i++) printf("%d%c", player[i].get_cnt(), " \n"[i == N]);
        for (int i = 1; i <= N; i++) player[i].display_card();
    }
    return 0;
}