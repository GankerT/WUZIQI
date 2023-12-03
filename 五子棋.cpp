
#include<bits/stdc++.h>
using namespace std;
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1  表示(3,6)的位置是黑子
*/
int mp[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;
// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

/*
    *难点1
    负责人: 张三
    功能: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

/*
    负责人: 张三
    功能: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)
        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    功能: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
*/
void menuView();

/*
    负责人: 张三
    功能: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap();

/*
    负责人: 张三
    功能: 根据flag的值  打印游戏胜利界面  用户可以按任意键回到主菜单
    参数: void
    返回值: void
*/
void winView();

/*
    *难点2
    负责人: 张三
    功能: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
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

    // 检查水平方向
    int count = 1; // 记录连续棋子数量
    int player = mp[x][y];

    // 向左检查
    for (int i = y - 1; i >= 0 && mp[x][i] == player; i--) {
        count++;
    }

    // 向右检查
    for (int i = y + 1; i < 19 && mp[x][i] == player; i++) {
        count++;
    }

    if (count >= 5) {
        return player; // 水平方向获胜
    }

    // 检查垂直方向
    count = 1;

    // 向上检查
    for (int i = x - 1; i >= 0 && mp[i][y] == player; i--) {
        count++;
    }

    // 向下检查
    for (int i = x + 1; i < 19 && mp[i][y] == player; i++) {
        count++;
    }

    if (count >= 5) {
        return player; // 垂直方向获胜
    }

    // 检查对角线方向（从左上到右下）
    count = 1;

    // 向上左检查
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0 && mp[i][j] == player; i--, j--) {
        count++;
    }

    // 向下右检查
    for (int i = x + 1, j = y + 1; i < 19 && j < 19 && mp[i][j] == player; i++, j++) {
        count++;

    }
    //cout<<count<<endl;


    if (count >= 5) {
        return player; // 对角线方向获胜（左上到右下）
    }

    // 检查对角线方向（从右上到左下）
    count = 1;

    // 向上右检查
    for (int i = x - 1, j = y + 1; i >= 0 && j < 19 && mp[i][j] == player; i--, j++) {
        count++;
    }

    // 向下左检查
    for (int i = x + 1, j = y - 1; i < 19 && j >= 0 && mp[i][j] == player; i++, j--) {
        count++;
    }

    if (count >= 5) {
        return player; // 对角线方向获胜（右上到左下）
    }

    return 0; // 无获胜
}


int playerMove(int x, int y) {
    if (mp[x][y] == 0) {
        if (flag % 2 == 0)mp[x][y] = 2;
        if (flag % 2 != 0)mp[x][y] = 1;
        //偶数轮黑子落子，奇数轮白子落子
        flag++;
        return 1;
    }
    else
        return 0;
}


void menuView() {
    while (1) {
        cout << "======== 五子棋游戏 ========" << endl;
        cout << "1. 进入游戏" << endl;
        cout << "2. 进入设置 (敬请期待...)" << endl;
        cout << "3. 退出游戏" << endl;

        int choice;
        cout << "请输入选项数字：";
        cin >> choice;

        switch (choice) {
        case 1:
            gameView(); // 进入游戏
            break;
        case 2:
            cout << "敬请期待...（设置功能未实现）" << endl;
            break;
        case 3:
            exit(0); // 退出游戏
            break;
        default:
            cout << "无效的选项，请重新输入。" << endl;
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
    cout << "游戏结束，";
    if (flag % 2 == 1) {
        cout << "白子胜利！";
    }
    else {
        cout << "黑子胜利！";
    }

    cout << "按任意键返回主菜单。" << std::endl;

    // 等待用户按任意键
    cin.ignore();
    cin.get();
}


void gameView() {
    while (1) {
        gameView_ShowMap();
        int x, y;
        cin >> x >> y; //输入要下的坐标
        if (playerMove(x, y)) { // 落子
            int result = isWin(x, y); // 判断游戏是否胜利
            if (result != 0) {
                gameView_ShowMap();
                winView(); // 胜利界面
                break; // 结束当前界面
            }
        }
        else {
            cout << "无效的落子，请重新输入。" << endl;
        }

        flag++; //换玩家
    }
}