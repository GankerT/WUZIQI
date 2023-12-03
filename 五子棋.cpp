
#include<bits/stdc++.h>
using namespace std;
/*
    ����:
        map[i][j]��ʾ����(i,j)��ֵ
        0��ʾ�յ�
        1��ʾ����
        2��ʾ����
    ��: map[3][6] = 1  ��ʾ(3,6)��λ���Ǻ���
*/
int mp[19][19];

// ��ʾ��ǰ�غ���  ż����ʾ��������  ������ʾ��������
// ��: flag = 20 ��ʾ��ǰ�ǵ�[20]������  �ɺڷ�����
int flag;
// -------------------- ������� --------------------


// -------------------- service --------------------
/*
    ������: ����
    ����: ��ʼ����Ϸ����
        �����̵�ֵ��ʼ��Ϊ0
        ��ǰ�غ���Ϊ����(flag��Ϊ0)
    ����: void
    ����ֵ: void
*/
void init();

/*
    *�ѵ�1
    ������: ����
    ����: ���ݴ��������(map��Ӧλ��)��flagֵ �ж������Ƿ��ʤ
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾû�л�ʤ
        1��ʾ����ʤ��
        2��ʾ����ʤ��
*/
int isWin(int x, int y);

/*
    ������: ����
    ����: ��ָ��λ������
        ���map[x][y]�ǿյ� ���޸�map[x][y]��ֵ:��Ϊ��Ӧ��ɫ(flag��Ӧ��ɫ)
        ���򲻲���
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾ����ʧ�� (�����Ѿ�����)
        1��ʾ���ӳɹ�

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    ����: չʾѡ��, ��ҿ���������ѡ�������Ϸ, �������û��˳���Ϸ
        ������Ϸ: ������Ϸ���溯��gameView();
        ��������: �����ڴ�...
        �˳���Ϸ: ����exit(0);
*/
void menuView();

/*
    ������: ����
    ����: ����map���� ��ӡ��Ϸ����
    ����: void
    ����ֵ: void
*/
void gameView_ShowMap();

/*
    ������: ����
    ����: ����flag��ֵ  ��ӡ��Ϸʤ������  �û����԰�������ص����˵�
    ����: void
    ����ֵ: void
*/
void winView();

/*
    *�ѵ�2
    ������: ����
    ����: ��Ϸ��������
        ��ʼ����Ϸ����(���ú���init())
        while(1){
            ��ӡ��Ϸ����(���ú���gameView_ShowMap())
            ���������������

            ����(�������Ӻ���playerMove())
                (�������ʧ�� ���¿�ʼѭ��)

            �ж���Ϸ�Ƿ�ʤ��(����ʤ���жϺ���isWin())
                (�����Ϸʤ�� ����ʤ�����溯�� Ȼ�������ǰ����)
            �л����(�޸�flagֵ)
        }
    ����: void
    ����ֵ: void
*/
void gameView();
// -------------------- view --------------------

int main()
{

}

void init() {
    flag = 0;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            mp[i][j] = 0;
        }
    }
}


int  isWin(int x, int y) {

    // ���ˮƽ����
    int count = 1; // ��¼������������
    int player = mp[x][y];

    // ������
    for (int i = y - 1; i >= 0 && mp[x][i] == player; i--) {
        count++;
    }

    // ���Ҽ��
    for (int i = y + 1; i < 19 && mp[x][i] == player; i++) {
        count++;
    }

    if (count >= 5) {
        return player; // ˮƽ�����ʤ
    }

    // ��鴹ֱ����
    count = 1;

    // ���ϼ��
    for (int i = x - 1; i >= 0 && mp[i][y] == player; i--) {
        count++;
    }

    // ���¼��
    for (int i = x + 1; i < 19 && mp[i][y] == player; i++) {
        count++;
    }

    if (count >= 5) {
        return player; // ��ֱ�����ʤ
    }

    // ���Խ��߷��򣨴����ϵ����£�
    count = 1;

    // ��������
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0 && mp[i][j] == player; i--, j--) {
        count++;
    }

    // �����Ҽ��
    for (int i = x + 1, j = y + 1; i < 19 && j < 19 && mp[i][j] == player; i++, j++) {
        count++;

    }
    //cout<<count<<endl;


    if (count >= 5) {
        return player; // �Խ��߷����ʤ�����ϵ����£�
    }

    // ���Խ��߷��򣨴����ϵ����£�
    count = 1;

    // �����Ҽ��
    for (int i = x - 1, j = y + 1; i >= 0 && j < 19 && mp[i][j] == player; i--, j++) {
        count++;
    }

    // ��������
    for (int i = x + 1, j = y - 1; i < 19 && j >= 0 && mp[i][j] == player; i++, j--) {
        count++;
    }

    if (count >= 5) {
        return player; // �Խ��߷����ʤ�����ϵ����£�
    }

    return 0; // �޻�ʤ
}


int playerMove(int x, int y) {
    if (mp[x][y] == 0) {
        if (flag % 2 == 0)mp[x][y] = 2;
        if (flag % 2 != 0)mp[x][y] = 1;
        //ż���ֺ������ӣ������ְ�������
        flag++;
        return 1;
    }
    else
        return 0;
}


void menuView() {
    while (1) {
        cout << "======== ��������Ϸ ========" << endl;
        cout << "1. ������Ϸ" << endl;
        cout << "2. �������� (�����ڴ�...)" << endl;
        cout << "3. �˳���Ϸ" << endl;

        int choice;
        cout << "������ѡ�����֣�";
        cin >> choice;

        switch (choice) {
        case 1:
            gameView(); // ������Ϸ
            break;
        case 2:
            cout << "�����ڴ�...�����ù���δʵ�֣�" << endl;
            break;
        case 3:
            exit(0); // �˳���Ϸ
            break;
        default:
            cout << "��Ч��ѡ����������롣" << endl;
            break;
        }
    }
}


void gameView_ShowMap() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }
}


void winView() {
    cout << "��Ϸ������";
    if (flag % 2 == 1) {
        cout << "����ʤ����";
    }
    else {
        cout << "����ʤ����";
    }

    cout << "��������������˵���" << std::endl;

    // �ȴ��û��������
    cin.ignore();
    cin.get();
}


void gameView() {
    while (1) {
        gameView_ShowMap();
        int x, y;
        cin >> x >> y; //����Ҫ�µ�����
        if (playerMove(x, y)) { // ����
            int result = isWin(x, y); // �ж���Ϸ�Ƿ�ʤ��
            if (result != 0) {
                gameView_ShowMap();
                winView(); // ʤ������
                break; // ������ǰ����
            }
        }
        else {
            cout << "��Ч�����ӣ����������롣" << endl;
        }

        flag++; //�����
    }
}