#include <iostream>
#include "tabtenn1.h"

using namespace std;

int main(void)
{
	TableTennisPlayer player1("xiaohui", "li", true);
	RatedPlayer rplayer1(11400, "xiaoming", "zhang", true);
	//使用基类的方法
	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": has a table." << endl;
	else
		cout << ": hasn't a table.";

	//使用继承类中的方法
	rplayer1.Name();
	cout << ": rating is " << rplayer1.Rating() << "." << endl;

	RatedPlayer rplayer2 (1212, player1);
	rplayer2.Name();
	cout << ": rating is " << rplayer2.Rating() << "." << endl;
	rplayer2.Name();
	return 0;
}
