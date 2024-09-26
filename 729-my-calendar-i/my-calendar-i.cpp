class MyCalendar {
    vector<pair<int, int>> bks;
public:
    bool book(int s, int e) {
        for (auto& [bs, be] : bks)
            if (s < be && bs < e) return false;
        bks.push_back({s, e});
        return true;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();