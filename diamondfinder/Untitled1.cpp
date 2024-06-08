
#include <windows.h>

#include <iostream>

using namespace std;

int main() {

SetConsoleTitle("Diamond Finder by caiji_233");

bool is_1_16;

char c;

long long seed, mask = 0xffffffffffff, mul = 25214903917, t1, t2, t3, t4, i, j, cx, cz, tx, tz, x, z, pos, p1, p2;

cout << "is 1.16 or 1.17 version?(1.16: 1,1.17: 0):";

cin >> is_1_16;

cout << "Input seed:";

cin >> seed;

t1 = ((seed ^ mul) & mask) * mul + 11 & mask;

t2 = t1 * mul + 11 & mask;

t3 = t2 * mul + 11 & mask;

t4 = t3 * mul + 11 & mask;

i = (t1 >> 16 << 32) + (t2 << 16 >> 32) | 1;

j = (t3 >> 16 << 32) + (t4 << 16 >> 32) | 1;

while(1) {

cout << "Input chunk's x position:";

cin >> cx;

cout << "Input chunk's z position:";

cin >> cz;

pos = ((cx * 16 * i + cz * 16 * j) ^ seed) + is_1_16 ? 60009 : 60011;

pos = (pos ^ mul) & mask;

p1 = pos * mul + 11 & mask;

p2 = p1 * mul + 11 & mask;

tx = p1 >> 44, x = tx + 16 * cx;

tz = p2 >> 44, z = tz + 16 * cz;

cout << "Diamond is in (" << x << ",?," << z << ")" << endl;

}

} 
