#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	char answer;
	static bool final(false); //设置一个判断是否游戏获胜的全局变量。
	int A(0),B(0); //A和B分别为游戏进行局数和获胜游戏局数。
	do{

		cout << "需要玩游戏吗 (Y/N)?";
		cin >> answer;
		if (answer == 'N') break;
		else{
			int result[3]={0};
			while(true)
			{
                srand(time(NULL));
                result[0]=rand()*10 / (RAND_MAX+1);
                result[1]=rand()*10 / (RAND_MAX+1);
                result[2]=rand()*10 / (RAND_MAX+1);
                if (result[0]!=result[1] &&
                    result[0]!=result[2] &&
                    result[1]!=result[2]) break;
			}                      //生成3个不同随机数。
			for (int i(0);i<7;++i){
				int guess[3];
				cout << "请输入你猜测的数字:"<<endl;
				cin >> guess[0] >> guess[1] >>guess[2];
				int a(0),b(0);//a和b分别为猜对的数字个数和猜对但位置不对的数字个数。
				for (int j(0);j < 3;++j){
					if (guess[j]==result[j]) ++a;
					  else {
					  	if(guess[j]==result[(j+1)%3] ||
						   guess[j]==result[(j+2)%3])
						   ++b;
					  }
				}

				if (a==3) {
					cout <<"恭喜，你猜对了。"<< endl;
                    final=true;
                    break;
				}
				else cout << a <<'A'<< b << 'B'<<endl;
			}
			++A;
			if (final) ++B;
            else cout <<"很遗憾，你没有在规定次数内猜对。答案是"
                      << result[0]<<result[1]<<result[2] << endl;
            final = false;
		}
	}while(answer=='Y');
	cout <<"你一共玩了" << A <<"局，赢了"
			<< B << "局，输了" << A-B << "局。";
}

