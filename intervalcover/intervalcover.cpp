/*
* Author: Erik Tedhamre
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> cover(pair<double, double> interval, vector<pair<double, double> > intervals){
    //Result vector
    vector<int> indices;
    double left_point = interval.first;
    double right_point = interval.second;
    bool point = false;
    if(left_point == right_point){
        point = true;
    }
    // Remove distance covered and instead use index to determine
    // if an interval has been chosen
    // Iterator used throughout search
    vector<pair<double, double> >::iterator it = intervals.begin();
    while(((left_point < right_point) || point) && it != intervals.end()){
        // Current best interval for current left most point
        int index_best_iterator = -1;
        // Pick the interval that covers the left most point
        // and as much of the rest as possible
        while( it != intervals.end() && left_point >= it->first){
            // This can probably be done better
            // We need something to compare with
            // For the first time the point is covered by the interval
            if ((index_best_iterator == -1) && (it->second >= left_point)){
                if(point){
                    index_best_iterator = (it - intervals.begin());
                    // Dodging if statements again
                    // Seems bad
                    break;
                }
                else{
                    index_best_iterator = (it - intervals.begin());
                }
            }
            else if((index_best_iterator != -1) && 
            (it->second > (intervals.begin() + index_best_iterator)->second)){
                index_best_iterator = (it - intervals.begin());
            }
            it = it + 1;
        }
        if(index_best_iterator == -1){
            // Add a -1 as index to the result vector
            // It's impossible to cover
            indices.push_back(-1);
            break;
        }
        else{
            // Move the left most point
            left_point = (intervals.begin() + index_best_iterator)->second;
            // Add best's index to the result vector
            indices.push_back(index_best_iterator);
            // Check if we have covered the entire intervall
            // Is done in the while-loop
            // reset distance_covered
            if(point){
                // Dodging if statements again
                // Seems bad
                left_point = right_point;
                break;
            }
            index_best_iterator = -1;
            // Restart search with new left most point
            // Where we left off
        }  
    }
    if((*(indices.end() - 1) == -1) || ((left_point < right_point) && (it == intervals.end()))){
        vector<int> bad;
        bad.push_back(-1);
        return bad;
    }

    return indices;
}

bool intervalCmp(const pair<double, double> &a, const pair<double, double> &b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main() {

    //Current interval
    double lower;
    double upper;
    int number_of_intervals;
    map<pair<double, double>, int> orig_index_map;
    vector<int> result;
    while(scanf("%lf %lf", &lower, &upper) != EOF){
        pair<double, double> interval = make_pair(lower, upper);
        vector<pair<double, double> > intervals;
        vector<int> curRes;
        scanf("%d", &number_of_intervals);
        // Zero intervals available
        // Don't think negative number of intervals is possible...
        // Break and look for next test-case
        if(number_of_intervals <=0){
            result.push_back(-1);
            goto print;
        }
        for(int i = 0; i < number_of_intervals; i++){
            pair<double, double> curr_interval;
            double curr_lower;
            double curr_upper;
            scanf("%lf %lf", &curr_lower, &curr_upper);
            curr_interval = make_pair(curr_lower, curr_upper);
            intervals.push_back(curr_interval);
            orig_index_map[curr_interval] = i;
        }
        // Sorting in ascending order on first element and then second element
        sort(intervals.begin(), intervals.end(), intervalCmp);
        curRes = cover(interval, intervals);
        // Push back current result,
        // unsure if we need to keep it until
        // all input is read or if we can simply print it
        if(curRes[0] == -1){
            result.push_back(-1);
        }
        else{
            int elems = curRes.size();
            result.push_back(elems);
            for(int i = 0; i < elems; i++){
                // Using element in curRes to get the index for
                // the sorted array and then using the value
                // from the sorted array to get the original value
                // from the map
                int sorted_index = curRes[i];
                pair<double, double> best_interval = intervals[sorted_index];
                int original_index = orig_index_map[best_interval];
                result.push_back(original_index);
            }
        }
        // Using goto statement for the first time
        print:
        for(int i = 0; i < result.size(); i++){
            if(result[i] == -1){
                printf("impossible");
                continue;
            }
            else if(i == 0){
                printf("%d\n", result[i]);
                continue;
            }
            else if (i == result.size() - 1)
            {
                printf("%d", result[i]);
            } 
            else{
                printf("%d ", result[i]);
            }
        }
        // For visability hopefully doesn't screw me over
        printf("\n");
        result.clear();
    };
}