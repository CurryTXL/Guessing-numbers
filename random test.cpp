#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	char answer;
	static bool final(false); //����һ���ж��Ƿ���Ϸ��ʤ��ȫ�ֱ�����
	int A(0),B(0); //A��B�ֱ�Ϊ��Ϸ���о����ͻ�ʤ��Ϸ������
	do{

		cout << "��Ҫ����Ϸ�� (Y/N)?";
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
			}                      //����3����ͬ�������
			for (int i(0);i<7;++i){
				int guess[3];
				cout << "��������²������:"<<endl;
				cin >> guess[0] >> guess[1] >>guess[2];
				int a(0),b(0);//a��b�ֱ�Ϊ�¶Ե����ָ����Ͳ¶Ե�λ�ò��Ե����ָ�����
				for (int j(0);j < 3;++j){
					if (guess[j]==result[j]) ++a;
					  else {
					  	if(guess[j]==result[(j+1)%3] ||
						   guess[j]==result[(j+2)%3])
						   ++b;
					  }
				}

				if (a==3) {
					cout <<"��ϲ����¶��ˡ�"<< endl;
                    final=true;
                    break;
				}
				else cout << a <<'A'<< b << 'B'<<endl;
			}
			++A;
			if (final) ++B;
            else cout <<"���ź�����û���ڹ涨�����ڲ¶ԡ�����"
                      << result[0]<<result[1]<<result[2] << endl;
            final = false;
		}
	}while(answer=='Y');
	cout <<"��һ������" << A <<"�֣�Ӯ��"
			<< B << "�֣�����" << A-B << "�֡�";
}

