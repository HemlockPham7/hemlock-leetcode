class Solution {
public:
    int getMonth(const string& str) {
        return stoi(str.substr(0, 2));
    }

    int getDay(const string& str) {
        return stoi(str.substr(3, 2));
    }

    int getTotalDays(const vector<int>& days, const string& str) {
        int totalDays = 0;
        int leaveMonth = getMonth(str);
        for (int i = 0; i < leaveMonth - 1; ++i) {
            totalDays += days[i];
        }
        int leaveDay = getDay(str);
        totalDays += leaveDay;
        return totalDays;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // ensure arriveAlice <= arrivceBob
        if (arriveAlice > arriveBob) {
            return countDaysTogether(arriveBob, leaveBob, arriveAlice, leaveAlice);
        }
        // LA < AB
        if (leaveAlice < arriveBob) {
            return 0;
        }
        // AA <= AB && LB <= LA
        if (leaveBob <= leaveAlice) {
            return getTotalDays(days, leaveBob) - getTotalDays(days, arriveBob) + 1;
        }
        return getTotalDays(days, leaveAlice) - getTotalDays(days, arriveBob) + 1;
    }
};