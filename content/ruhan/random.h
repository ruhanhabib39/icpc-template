/**
 * Author: Ruhan Habib
 * Date:
 * License: 
 * Source:
 * Description: Nice uniform real/int distribution wrapper
 * Time: 
 * Status: untested
 */

random_device non_deterministic_generator;
//mt19937 mersenne_generator(non_deterministic_generator());
mt19937 mersenne_generator(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mersenne_generator_64(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist1(lo, hi);
uniform_real_distribution<> dist2(lo, hi);

// Usage

int val = mersenne_generator();
long long val2 = mersenne_generator_64();
int val3 = dist1(mersenne_generator);
double val4 = dist2(mersenne_generator);

shuffle(vec.begin(), vec.end(), mersenne_generator);
