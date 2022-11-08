#define _CRT_SECURE_NO_WARNINGS
#define M 100

using namespace std;
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include"ctime"
#include<cstring>

//类型定义
const int factor[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };//加权因子 
const string A[] = {
"11","12","13","14","15",//京、津、冀、晋、蒙
"21","22","23",//辽、吉、黑
"31","32","33","34","35","36","37",//泸、苏、浙、皖、闽、赣、鲁
"41","42","43","44","45","46",//豫、鄂、湘、粤、桂、琼
"50","51","52","53","54",//渝、川、贵、云、藏 
"61","62","63","64","65"//陕、甘、青、宁、新
};//前两位
const int checktable[] = { 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2 };//校验值对应表 
const string Class[] = { "程序设计","C++","英语","数据结构","Java","数学逻辑" };
//课程类
struct course {
	string coursename;
	double grade;
};
//人类
class person {
public:
	string name;
	string born;
	string spe;
	string num;//学号
	string sex;
	string phone;
	string college;
	string id;
	string class_number;//班级号
	double allgrade;
	person() {
		name = "无";
		born = "无";
		spe = "无";
		num = "0";
		sex = "无";
		phone = "0";
		college = "无";
		id = "0";
		class_number = "0";
		allgrade = 0;
	}
};
//学生类 -> 继承自person类
class student :public person {
public:
	course cs[9];//九门课
	student() {//构造函数
		for (int i = 0; i < 9; i++) {
			cs[i].coursename = "#";
			cs[i].grade = 0;
		}
	}
};
//用户类
class user {
public:
	string ac;//账号 
	string pw;//密码
	string name;//姓名
	string sex;//性别
	string idt;//身份 
	string age;//年龄
	user() {//构造函数
		ac = "#";
		pw = "#";
		name = "#";
		sex = "#";
		idt = "#";
		age = "#";
	}
};

/*声明*/
//从 studentlist.txt 中读取学生信息
int ReadStu(student a[]);
//从 用户信息.txt 中读取用户信息
int ReadUser(user b[]);
//从 SetBasic.txt 中读取信息
int ReadSB(student b[]);
// 学生信息输出
void PSt(student a);
//保存用户信息 向后添加
void getUser(user c);
//更改用户信息 覆盖
void getUserc(user d[]);
//记录更改时间
void time();
//输入基本信息 + 数据校验
void setBasic1(student a[]);
//直接向 studentlist.txt 中添加信息
void getfile(student a[], string i);
//修改 studentlist.txt 中的信息，需要覆盖
void getfile_cov(student a[]);
//导出到文件 学生全体
void allgetfile(student a[]);
//身份证校验
bool RID(string MYID);
//输入基本信息 + 数据校验
void setBasic1(student a[]);
//文件读取 + 数据校验
void setBasic2(student a[]);
//某位同学的某门成绩的录入 - 感觉更像成绩修改，带改
void getgrade1(student a[]);

//信息录入菜单
void getmenu1();
//成绩录入菜单
void grademenu(student a[]);
//信息录入菜单
void getmenu3(student a[]);
//按学号导出信息
void getmenu2(student a[]);
//批量修改菜单 
void momenu(student a[]);
//修改成绩菜单
void nummenu(student a[]);
//实现输入给定学号，修改指定学生部分信息菜单
void modify1(student a[]);
//修改指定学生信息菜单
void modimenu(student a[]);
//查询指定学生信息菜单
void numfind(student a[]);
//成绩统计菜单 
void cjmenu(student a[]);
//删除菜单
void deletemenu(student a[]);
//查询菜单 - 包括查询指定学生信息
void findmenu(student a[]);
//排序菜单
void sortmenu(student a[]);
//管理员操作菜单 
void guanliyuanmenu(user b[], user c[], user d[], int i, student a[]);
//教师操作菜单 
void jiaoshimenu(student a[]);
//学生操作菜单
void xueshengmenu(user b[], int i, student a[]);

//不同专业的课程导入
void setcourse(student a[]);
//批量修改信息
void modification1(student a[], int m);
//按照学号修改全部课程成绩
void num_mod1(student a[]);
//学号修改指定课程成绩
void num_mod2(student a[]);
//姓名修改指定课程成绩
void num_mod3(student a[]);
//修改日志写入
void indata(string a, string b, string c);
//按学生姓名查找 - 包含字段查询
void findName(student a[]);
//按班级查找
void findinfor(student a[]);
//查找某科目的成绩 - 输出符合条件学生的信息
void select1(student a[]);
//查询不及格课程数目
void select2(student a[]);
//生成柱状图
void zhuzhuangtu(int s[]);
//统计成绩，由教师操作
void tongjicj(student a[]);
//按学号查询指定同学全部信息
void search1(student a[]);
//按学号查询该学院全部同学信息
void search2(student a[]);
//按学号查询指定同学全部成绩信息
void search3(student a[]);
//按学号查询指定同学指定课程的成绩
void search4(student a[]);

//删除班级
void shanchu(student a[]);
//根据学号删除所在班级
void alldelete(student a[]);
//按照学号删除指定学生
void xuehao_shan(student a[]);
//按照姓名删除指定学生
void xingming_shan(student a[]);

//按照总成绩排序
void sort(student a[]);
//输入班级后按总成绩降序输出学生信息
void sort01(student a[]);
//按专业指定课程成绩降序 
void zysort(student a[]);
//管理员浏览学生基本信息
void allliulan(student a[]);
//管理员添加用户信息
void adduser(user c[]);

//学生浏览个人信息 
void liulanxx(string b, int i, student a[]);
//学生浏览个人成绩
void liulancj(string b, int i, student a[]);
//用户浏览用户信息
void userliulan(user d[]);
//实现输入给定用户账号，修改指定用户的部分信息
void modifyYH(user c[]);
//按照账号删除指定用户 - 未验证
void deleteYH(user c[]);
//注册用户 - 未增加 studentm.txt、和teacherm.txt 与用户信息同步
void enroll(user b[]);
void login(user b[], user c[], user d[], student a[]);

int main() {
	int m = -1;
	int i = 0;
	student s[M];
	student a[M];
	int num = 0;
	num = ReadStu(a);
	user b[M], c[M], d[M];
	num = ReadUser(b);
	login(b, c, d, a);
	return 0;
}

//函数体
/*文件相关*/
//从 studentlist.txt 中读取学生信息
int ReadStu(student a[])
{
	ifstream fin;
	int i = 0;
	int num = 0;
	fin.open("studentlist.txt");
	if (!fin.is_open())
	{
		cout << "open error!" << endl;
		exit(0);
	}
	while (fin.peek() != EOF) {
		fin >> a[num].num
			>> a[num].name
			>> a[num].sex
			>> a[num].spe
			>> a[num].born
			>> a[num].phone
			>> a[num].college
			>> a[num].id
			>> a[num].class_number
			>> a[num].allgrade;
		for (int j = 0; j < 9;)
		{
			fin >> a[num].cs[j].coursename;
			if (a[num].cs[j].coursename == "#")
				break;
			else
			{
				fin >> a[num].cs[j].grade;
				j++;
			}
		}
		if (a[num].num == "0")
			break;
		num++;
	}
	fin.close();
	return num;
}
//从 用户信息.txt 中读取用户信息
int ReadUser(user b[])
{
	int num = 0;
	ifstream fp;
	fp.open("用户信息.txt");
	if (!fp.is_open())
	{
		cout << "open error!" << endl;
		exit(0);
	}
	while (fp.peek() != EOF) {
		fp >> b[num].ac
			>> b[num].name
			>> b[num].pw
			>> b[num].sex
			>> b[num].idt
			>> b[num].age;
		num++;
	}
	return num;
}
//从 SetBasic.txt 中读取信息
int ReadSB(student b[])
{
	int n = 0;
	ifstream fin;
	fin.open("SetBasic.txt");
	char v;
	while (fin.peek() != EOF) {
		fin >> b[n].num
			>> b[n].name
			>> b[n].sex
			>> b[n].spe
			>> b[n].born
			>> b[n].phone
			>> b[n].college
			>> b[n].id
			>> b[n].class_number
			>> b[n].allgrade
			>> b[n].cs[0].coursename
			>> b[n].cs[0].grade
			>> b[n].cs[1].coursename
			>> b[n].cs[1].grade
			>> b[n].cs[2].coursename
			>> b[n].cs[2].grade
			>> v;
		n++;
	}
	fin.close();
	return n;
}
//将某学生的信息写入 studentlist.txt 文件之中 - 直接向后加
void getfile(student a[], string i) {
	int m = 0;
	ofstream outfile("studentlist.txt", ios::app);
	if (!outfile) {
		cout << "打开文件失败！" << endl;
		return;
	}
	cout << "是否保存信息，1为是，0为否，请输入:" << endl;
	int w;
	cin >> w;
	system("cls");
	if (w) {
		for (int n = 0; n < M; n++) {
			if (a[n].num == i) {
				m = n;
				break;
			}
		}
		a[m].allgrade = a[m].cs[0].grade + a[m].cs[1].grade + a[m].cs[2].grade;
		outfile << a[m].num << "  ";
		outfile << a[m].name << "  ";
		outfile << a[m].sex << "  ";
		outfile << a[m].spe << "  ";
		outfile << a[m].born << "  ";
		outfile << a[m].phone << "  ";
		outfile << a[m].college << "  ";
		outfile << a[m].id << "  ";
		outfile << a[m].class_number << "  ";
		outfile << a[m].allgrade << "  ";
		for (int j = 0; j < 9; j++) {
			outfile << a[m].cs[j].coursename << " "
				<< a[m].cs[j].grade << " ";
			if (a[m].cs[j + 1].coursename == "#")
			{
				outfile << "#" << endl;
				break;
			}
		}
		outfile << endl;
		outfile.close();

		cout << "保存成功！" << endl;
	}
}
//修改 studentlist.txt 中的信息，需要覆盖
void getfile_cov(student a[])
{
	cout << "是否要将信息保存到数据库？（1是0否）" << endl;
	int n = -1;
	cin >> n;
	if (n)
	{
		ofstream outfile("studentlist.txt");
		if (!outfile)
		{
			cout << "失败！" << endl;
			return;
		}
		for (int i = 0; i < M; i++)
		{
			if (a[i].num == "0")   break;
			a[i].allgrade = a[i].cs[0].grade + a[i].cs[1].grade + a[i].cs[2].grade;
			outfile << a[i].num << "  ";
			outfile << a[i].name << "  ";
			outfile << a[i].sex << "  ";
			outfile << a[i].spe << "  ";
			outfile << a[i].born << "  ";
			outfile << a[i].phone << "  ";
			outfile << a[i].college << "  ";
			outfile << a[i].id << "  ";
			outfile << a[i].class_number << "  ";
			outfile << a[i].allgrade << "  " << endl;
			for (int j = 0; j < 9; j++)
			{
				if (a[i].cs[j].coursename == "#")
				{
					outfile << "#" << endl;
					break;
				}
				outfile << a[i].cs[j].coursename << " " << a[i].cs[j].grade << " ";
			}
			outfile << endl;
		}
		outfile.close();
		cout << "修改信息保存成功！" << endl;
		system("pause");
	}
}
//导出到文件 学生全体
void allgetfile(student a[]) {
	ofstream outfile("studentlist.txt", ios::app);
	if (!outfile)
	{
		cout << "打开文件失败！" << endl; return;
	}
	cout << "是否保存信息，1为是，0为否，请输入:" << endl;
	int n;
	cin >> n;
	system("cls");//清空之前的结果
	if (n)
	{
		for (int i = 0; i < M; i++) {
			if (a[i].num == "0")   break;
			outfile << a[i].num << endl;
			outfile << a[i].name << endl;
			outfile << a[i].sex << endl;
			outfile << a[i].spe << endl;
			outfile << a[i].born << endl;
			outfile << a[i].phone << endl;
			outfile << a[i].college << endl;
			outfile << a[i].id << endl;
			outfile << a[i].class_number << endl;
			for (int j = 0; j < 9; j++) {
				if (a[i].cs[j].coursename == "#")   break;
				outfile << a[i].cs[j].coursename << ' ' << a[i].cs[j].grade << endl;
				if (a[i].cs[j + 1].coursename == "#")   break;
			}
			cout << endl;
		}
		outfile.close();
		cout << "保存成功！" << endl;
	}
}
//保存用户信息 向后添加
void getUser(user c)
{
	int k = 0;
	cout << "是否保存添加的用户信息：【1】确定 【0】取消" << endl;
	cin >> k;
	if (k) {
		ofstream file("用户信息.txt", ios_base::app);
		if (!file) { cout << "失败！" << endl; return; }
		file << endl;
		file << c.ac << "   ";
		file << c.name << "   ";
		file << c.pw << "   ";
		file << c.sex << "   ";
		file << c.idt << "   ";
		file << c.age << endl;
		file.close();
		if (c.idt == "老师") {
			ofstream outfile("teacherm.txt", ios_base::app);
			if (!outfile) { cout << "失败！" << endl; return; }
			outfile << endl;
			outfile << c.ac << "   ";
			outfile << c.name << "   ";
			outfile << c.pw << "   ";
			outfile << c.sex << "   ";
			outfile << c.idt << "   ";
			outfile << c.age << endl;

			outfile.close();
		}
		if (c.idt == "学生") {
			ofstream outfile("studentm.txt", ios_base::app);
			if (!outfile) { cout << "失败！" << endl; return; }
			outfile << endl;
			outfile << c.ac << "   ";
			outfile << c.name << "   ";
			outfile << c.pw << "   ";
			outfile << c.sex << "   ";
			outfile << c.idt << "   ";
			outfile << c.age << endl;
			outfile.close();
		}
		cout << "添加成功！" << endl;
	}
}
//更改用户信息 覆盖
void getUserc(user d[])
{
	ofstream off("用户信息.txt");
	if (!off) {
		cout << "失败！" << endl;
		return;
	}
	for (int i = 0; i < M; i++)
	{
		if (d[i].pw == "#")   break;
		off << setiosflags(ios::left) << setw(13) << d[i].ac;
		off << setw(10) << d[i].name;
		off << setw(10) << d[i].pw;
		off << setw(6) << d[i].sex;
		off << setw(7) << d[i].idt;
		off << setw(4) << d[i].age;
		off << endl;
	}
	off.close();
}

// 学生信息输出
void PSt(student a)
{
	if (a.num == "0")
		return;
	cout << setw(13) << " 学号:" << a.num << endl
		<< setw(13) << " 姓名:" << a.name << endl
		<< setw(13) << " 性别:" << a.sex << endl
		<< setw(13) << " 专业:" << a.spe << endl
		<< setw(13) << " 出生日期:" << a.born << endl
		<< setw(13) << " 电话:" << a.phone << endl
		<< setw(13) << " 学院:" << a.college << endl
		<< setw(13) << " 身份证号码:" << a.id << endl
		<< setw(13) << " 班级编号:" << a.class_number << endl
		<< setw(13) << "总成绩：" << a.allgrade << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << setw(13) << a.cs[i].coursename << "：" << a.cs[i].grade << endl;
		if (a.cs[i + 1].coursename == "#")   break;
	}
}
//身份证号校验
bool RID(string MYID) {
	int b = 0;
	if (MYID.length() != 18) return 0;//长度校验
	else {
		for (int v = 0; v < 31; v++) {//前两位校验
			if (MYID.substr(0, 2) == A[v]) {
				b = 1; break;
			}
		}
		if (b == 0 && MYID.substr(0, 2) != A[30])
			return 0;
	}
	int id[19] = { 0 };
	for (int i = 0; i < 17; i++)//相当于类型转换
		id[i] = MYID[i] - '0';
	if (MYID[17] == 'X')
		id[17] = 10;
	else id[17] = MYID[17] - '0';
	int i = 0;
	int checksum = 0;
	for (; i < 17; i++)
		checksum += id[i] * factor[i];
	string B;
	B = MYID.substr(6, 4);
	if (B > "2022")
		return 0;
	string C;
	C = MYID.substr(10, 2);
	if (C > "12" || C == "00")
		return 0;
	string D;
	D = MYID.substr(12, 2);
	if (D > "31")
		return 0;
	if (id[17] == checktable[checksum % 11])
		return 1;
	if (id[17] == 10 && checksum % 11 == 2)
		return 1;
	else return 0;
}
//记录更改时间
void time() {
	time_t now_time;
	now_time = time(NULL);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&now_time));
	ofstream outfile("data.txt", ios_base::app);
	if (!outfile)
	{
		cout << "打开文件失败！" << endl;
	}
	outfile << "记录时间：" << tmp;
	outfile << endl;
	outfile.close();
}
//输入基本信息 + 数据校验
void setBasic1(student a[]) {
	int n = 0;
	cout << setw(17) << "请输入学号: ";
	cin >> a[n].num; cout << endl;
	while (a[n].num.length() != 10 || a[n].num.substr(0, 2) < "19" || a[n].num.substr(0, 2) > "22") {
		//判断学号前两位是否是19，20，21，22 以及 学号位数是否正确
		cout << "学号输入有误，请重新输入" << endl;
		cin >> a[n].num;
	}
	cout << setw(17) << "请输入姓名: ";
	cin >> a[n].name; cout << endl;
	cout << setw(17) << "请输入专业: ";
	cin >> a[n].spe; cout << endl;
	cout << setw(17) << "请输入电话: ";
	cin >> a[n].phone; cout << endl;
	while (a[n].phone.length() != 11) {
		cout << "电话号输入有误，请重新输入" << endl;
		cin >> a[n].phone;
	}
	cout << setw(17) << "请输入学院: ";
	cin >> a[n].college; cout << endl;
	cout << setw(17) << "请输入身份证号码: ";
	cin >> a[n].id; cout << endl;
	while (RID(a[n].id) == false)//中间八位校验仍未完善
	{
		cout << "身份证号输入有误，请重新输入" << endl;
		cin >> a[n].id;
	}
	if ((a[n].id[16] - '0') % 2 == 0)//利用身份证号补充性别信息
	{
		a[n].sex = "女";
	}
	else if ((a[n].id[17] - '0') % 2 == 1)
		a[n].sex = "男";

	a[n].born = a[n].id.substr(6, 4) + '.' + a[n].id.substr(10, 2) + '.' + a[n].id.substr(12, 2);
	int j = 0;
	a[n].class_number = a[n].num.substr(0, 8);//利用学号补充班级编号信息
	for (int i = 0; i < 3; i++)
	{
		cout << setw(17) << "请输入要录入的科目 ";
		cin >> a[n].cs[i].coursename;
		cout << endl;
	s:		for (j = 0; j < 9; j++)
	{
		if (a[n].cs[i].coursename == Class[j])
			break;
	}
	if (j == 9 && a[n].cs[i].coursename.compare(Class[8]) != 0)
	{
		cout << "查无此科目，请重新输入" << endl;
		cin >> a[n].cs[i].coursename;
		goto s;
	}
	cout << setw(17) << "请输入成绩: ";
	cin >> a[n].cs[i].grade; cout << endl;
	while (a[n].cs[i].grade > 100 || a[n].cs[i].grade < 0)
	{
		cout << "成绩错误，请重新输入！" << endl;
		cin >> a[n].cs[i].grade;
	}
	}
	cout << "您刚才录入的基本信息为:" << endl;
	PSt(a[n]);
	getfile(a, a[n].num);
}
//文件读取 + 数据校验
void setBasic2(student a[]) {
	int num = 0;
	num = ReadSB(a);
	cout << "此次批量录入的基本信息库为:" << endl;
	int i = 0;
	for (i = 0; i < num; i++) {
		if (a[i].num == "0") break;
		while (a[i].phone.length() != 11) {
			cout << a[i].name << "电话号输入有误，请重新输入" << endl;
			cin >> a[i].phone;
		}
		while (a[i].num.length() != 10 || a[i].num.substr(0, 2) < "19" || a[i].num.substr(0, 2) > "22") {//判断学号前两位是否是19，20，21，22 以及 学号位数是否正确
			cin >> a[i].num;
		}
		while (a[i].class_number.length() != 8 && a[i].class_number != a[i].num.substr(0, 8)) {
			a[i].class_number = a[i].num.substr(0, 8);
		}
		while (RID(a[i].id) == false)//中间八位校验仍未完善
		{
			cout << a[i].name << "身份证号输入有误，请重新输入" << endl;
			cin >> a[i].id;
		}
		if ((a[i].id[17] - '0') % 2 == 0 && a[i].sex == "男")//信息错误
		{
			a[i].sex = "女";
		}
		else if ((a[i].id[17] - '0') % 2 == 1 && a[i].sex == "女")//信息错误
		{
			a[i].sex = "男";
		}
		if (a[i].born.substr(0, 4) != a[i].id.substr(6, 4))
			a[i].born = a[i].id.substr(6, 4) + '.' + a[i].id.substr(10, 2) + '.' + a[i].id.substr(12, 2);
		if (a[i].born.substr(5, 2) != a[i].id.substr(10, 2))
			a[i].born = a[i].id.substr(6, 4) + '.' + a[i].id.substr(10, 2) + '.' + a[i].id.substr(12, 2);
		if (a[i].born.substr(8, 2) != a[i].id.substr(12, 2))
			a[i].born = a[i].id.substr(6, 4) + '.' + a[i].id.substr(10, 2) + '.' + a[i].id.substr(12, 2);
		int j = 0;
		for (int v = 0; v < 3; v++)
		{
		s1:		for (j = 0; j < 9; j++)
		{
			if (a[i].cs[v].coursename == Class[j])
				break;
		}
		if (j == 9 && a[i].cs[v].coursename.compare(Class[8]) != 0)
		{
			cout << a[i].name << "的" << a[i].cs[v].coursename << "课程名输入有误，请重新输入" << endl;
			cin >> a[i].cs[v].coursename;
			goto s1;
		}
		while (a[i].cs[v].grade > 100 || a[i].cs[v].grade < 0)
		{
			cout << a[i].name << "的" << a[i].cs[v].grade << "的成绩输入有误，请重新输入" << endl;
			cin >> a[i].cs[v].grade;
		}
		}
		cout << endl << "------" <<
			"第" << i + 1 << "位学生:" << "------------" << endl;
		PSt(a[i]);
		getfile(a, a[i].num);
	}
}
//某位同学的某门成绩的录入 - 感觉更像成绩修改，带改
void getgrade1(student a[]) {
	int n = -1;
	int m = -1;
	cout << "请输入要录入成绩的学生学号:";
	string x;
	cin >> x;//2151030306
	for (int i = 0; i < M; i++)
	{
		if (a[i].num == x)
		{
			n = i; break;
		}
	}
	if (n == -1) cout << "查无此人" << endl;
	if (n != -1)
	{
		cout << "请输入要录入的科目:";
		string y;
		cin >> y;//程序设计
		for (int j = 0; j < 9; j++)
		{
			if (a[n].cs[j].coursename == y)
			{
				m = j;
				cout << "请输入要录入的成绩:";
				double z;
				cin >> z;//100
				while (z < 0 || z>100) {
					cout << "成绩错误，请重新输入：" << endl;
					cin >> z;
				}
				a[n].cs[j].grade = z; break;
			}
		}
		if (m == -1)
			cout << "查无此科目" << endl;
		if (m != -1)
		{
			cout << a[n].name << "  ";
			for (int i = 0; i < 9; i++)//输出验证 
			{
				if (a[n].cs[i].coursename == "#") break;
				cout << a[n].cs[i].coursename << "  " << a[n].cs[i].grade << "  ";
			}
			cout << endl;
			getfile_cov(a);
		}
	}
}
//不同专业的课程导入
void setcourse(student a[]) {
	int n, j = 0;
	string s, cn;
	cout << "是否输入课程？【1】是，【0】否" << endl;
	cin >> n;
	while (n) {
		cout << "请输入班级编号：" << endl;
		cin >> s;
		while (n) {
			cout << "请输入课程名称" << endl;
			cin >> cn;
			for (int i = 0; i < M; i++) {
				if (a[i].num == "#") break;
				if (a[i].class_number == s)
					a[i].cs[j].coursename = cn;
			}
			j++;
			cout << "是否继续输入课程？【1】是，【0】否" << endl;
			cin >> n;
		}
		for (int i = 0; i < M; i++) {
			if (a[i].num == "#") break;
			if (a[i].class_number == s) {

				cout << a[i].name << " ";

				for (int j = 0; j < 9; j++) {
					if (a[i].cs[j].coursename == "#") break;

					cout << a[i].cs[j].coursename << endl;
					cout << endl;
				}
			}
		}
		cout << "是否输入另一个班级课程？【1】是，【0】否" << endl;
		cin >> n; j = 0;
	}
}
//批量修改信息
void modification1(student a[], int m) {//将y批量改为x 
	int n = 0;
	int jige = 0;
	int flag;
	string y;
	string x;
	cout << "原内容:";  cin >> y;
	cout << "修改为:";  cin >> x;
	time();
	ofstream outfile("data.txt", ios_base::app);
	if (!outfile) {
		cout << "打开文件失败！" << endl;
	}
	outfile << "批量将 " << y << " 修改为 " << x << endl;
	outfile.close();
	flag = m;
	int num = ReadStu(a);
	for (n = 0; n < num; n++)
	{
		string m1 = y;
		switch (flag) {
		case 1:
			m1 = a[n].spe;
			if (m1 == y) {
				a[n].spe = x;
				jige++;
			}break;
		case 2:
			m1 = a[n].college;
			if (m1 == y) {
				a[n].college = x;
				jige++;
			}break;
		case 3:
			m1 = a[n].class_number;
			if (m1 == y) {
				a[n].class_number = x;
				jige++;
			}break;
		case 4:
			for (int i = 0; i < 9; i++) {
				m1 = (a[n].cs[i].coursename);
				if (m1 == y) {
					a[n].cs[i].coursename = x;
					jige++;
				}
			}break;
		}
	}
	cout << "---------------------------------" << endl;
	cout << "共查找到" << jige << "处“" << y << "”，现已全部修改为“" << x << "”。" << endl;
	cout << "---------------------------------" << endl;
	cout << "-----------------------------------" << endl << "学生信息库内容为:" << endl;
	for (int k = 0; k < M; k++)
	{
		if (a[k].num == "0")
			break;
		PSt(a[k]);
		cout << "---------------------------------" << endl;
	}

	getfile_cov(a);
	cout << "---------------------------------" << endl;

}
//按照学号修改全部课程成绩
void num_mod1(student a[]) {
	int n = 0, num = 0;
	string j;
	cout << "请输入要修改学生的学号" << endl;
	cin >> j;
	num = ReadStu(a);
	for (n = 0; n < num; n++)
		if (a[n].num == j) {//改数据
			time();
			ofstream outfile("data.txt", ios_base::app);
			if (!outfile) {
				cout << "打开文件失败！" << endl;
			}
			outfile << "学号" << a[n].num << "的原成绩:" << endl;
			for (int i = 0; i < 9; i++)
			{
				if (a[n].cs[i].coursename == "#") break;
				outfile << a[n].cs[i].coursename << " " << a[n].cs[i].grade << "    ";
			}
			outfile.close();
			for (int i = 0; i < 9; i++)
			{
				if (a[n].cs[i].coursename == "#")
					break;
				cout << "请输入该学生" << a[n].cs[i].coursename << "的成绩" << endl;
				cin >> a[n].cs[i].grade;
				while (a[n].cs[i].grade < 0 || a[n].cs[i].grade>100) {
					cout << a[n].name << "的" << a[n].cs[i].coursename << "不符合要求,请重新输入:" << endl;
					cin >> a[n].cs[i].grade;
				}
			}
			cout << endl << " 修改后的学生信息为:" << endl;
			PSt(a[n]);
			outfile.open("data.txt", ios_base::app);
			if (!outfile) {
				cout << "打开文件失败！" << endl;
			}
			for (int i = 0; i < 9; i++)
			{
				if (a[n].cs[i].coursename == "#")
					break;
				outfile << "修改为:" << a[n].cs[0].grade << " " << a[n].cs[1].grade << " " << a[n].cs[2].grade << endl;
				outfile.close();
			}
		}
	getfile_cov(a);
}
//学号修改指定课程成绩
void num_mod2(student a[]) {
	int n = 0;
	string j;
	cout << "请输入要修改学生的学号" << endl;
	cin >> j;
	int num = ReadStu(a);
	for (n = 0; n < num; n++)
		if (a[n].num == j) {
			string h;
			cout << "请输入要修改学生的课程" << endl;
			cin >> h;
			int m = 0;
			for (; m < 3; m++) {
				if (a[n].cs[m].coursename == h) {
					time();
					ofstream outfile("data.txt", ios_base::app);
					if (!outfile) {
						cout << "打开文件失败！" << endl;
					}
					outfile << "学号" << a[n].num << "的" << h << "成绩" << a[n].cs[m].grade << endl;
					outfile.close();
					cout << "请输入修改后的课程成绩" << endl;
					cin >> a[n].cs[m].grade;
					while (a[n].cs[m].grade < 0 || a[n].cs[m].grade>100) {
						cout << a[n].name << "的" << a[n].cs[m].coursename << "不符合要求,请重新输入:" << endl; cin >> a[n].cs[m].grade;
						ofstream outfile("data.txt", ios_base::app);
						if (!outfile) {
							cout << "打开文件失败！" << endl;
						}
						outfile << "修改为" << a[n].cs[m].grade << endl;
						outfile.close();
					}
					break;
				}
			}
			if (m == 3)cout << "输入课程有误,信息未被修改" << endl;
			else {
				cout << endl << "修改后的学生信息为:" << endl;
				cout << setiosflags(ios::left) << setw(13) << a[n].num
					<< setw(10) << a[n].name
					<< setw(8) << a[n].sex
					<< setw(20) << a[n].born
					<< setw(30) << a[n].id
					<< setw(25) << a[n].phone
					<< setw(27) << a[n].college
					<< setw(25) << a[n].spe
					<< setw(15) << a[n].class_number
					<< setw(9) << a[n].cs[0].grade + a[n].cs[1].grade + a[n].cs[2].grade
					<< setw(12) << a[n].cs[0].coursename
					<< setw(9) << a[n].cs[0].grade
					<< setw(12) << a[n].cs[1].coursename
					<< setw(9) << a[n].cs[1].grade
					<< setw(12) << a[n].cs[2].coursename
					<< setw(9) << a[n].cs[2].grade << endl;
			}
		}
	getfile_cov(a);
}
//姓名修改指定课程成绩
void num_mod3(student a[]) {
	string j;
	int s;
	int f[M];
	for (int p = 0; p < M; p++) {
		f[p] = 0;
	}
	cout << "请输入要修改学生的姓名" << endl;
	cin >> j;
	int n = 0;
	int g = 0;
	int r;
	int num = ReadStu(a);
	for (n = 0; n < num; n++)
		if (a[n].name == j) {
			f[g] = n;
			g++;
		}
	if (g != 0)
	{
		if (g > 1)
		{
			for (int u = 0; u < g; u++) {
				n = f[u];
				s = u + 1;
				cout << "第" << s << "个同名学生的学号为" << a[n].num << endl;
			}
			cout << "请输入选择修改第几个同名学生" << endl;
			int flag = 0;
			cin >> r;
			while (flag == 0)
			{
				if (r > s) {
					cout << "未查询到请重新输入：";
					cin >> r;
				}
				else flag = 1;
			}
		}
		string h;
		if (g > 1)
			n = f[r-1];
		else if (g == 1)
			n = f[0];
		cout << "请输入要修改学生的课程" << endl;
		cin >> h;
		int m = 0;
		for (; m < 9; m++) {
			if (a[n].cs[m].coursename == "#") break;
			else if (a[n].cs[m].coursename == h) {
				ofstream outfile("data.txt", ios_base::app);
				if (!outfile) {
					cout << "打开文件失败！" << endl;
				}
				outfile << "学号" << a[n].num << "的" << a[n].cs[m].coursename << "成绩：" << a[n].cs[m].grade << endl;
				outfile.close();
				cout << "请输入修改后的课程成绩" << endl;
				cin >> a[n].cs[m].grade;
				outfile.open("data.txt", ios_base::app);
				if (!outfile) {
					cout << "打开文件失败！" << endl;
				}
				outfile << "修改为：" << a[n].cs[m].grade << endl;
				outfile.close();
				while (a[n].cs[m].grade < 0 || a[n].cs[m].grade>100) {
					cout << a[n].name << "的" << a[n].cs[m].coursename << "不符合要求,请重新输入:" << endl;
					cin >> a[n].cs[m].grade;
				}
				a[n].allgrade = a[n].cs[0].grade + a[n].cs[1].grade + a[n].cs[2].grade;
				break;
			}
		}
		if (m == 9 && a[n].cs[m].coursename != h)cout << "输入课程有误,信息未被修改" << endl;
		else {
			cout << endl << "修改后的学生信息为:" << endl;
			PSt(a[n]);
			getfile_cov(a);
		}
	}
	else if (g == 0)
	{
		cout << "查无此人" << endl;
		system("pause");
	}
}
//修改日志写入
void indata(string a, string b, string c) {
	string p = a, q = b, t = c;
	time();
	ofstream outfile("data.txt", ios_base::app);
	if (!outfile) {
		cout << "打开文件失败！" << endl;
	}
	outfile << "将学号" << c << "的信息:" << p << "修改为：" << q << endl;
	outfile.close();
}
//实现输入给定学号，修改指定学生部分信息菜单
void modify1(student a[]) {
	int m = 0;
	int num = ReadStu(a);
	int d = 1;
	string y;
	cout << "请输入要进行修改信息的学生学号:";//做出提示 
	string x;
	cin >> x;                           //输入字符串学号 
	while (d)
	{
		cout << "-------------修改学生部分信息-------------" << endl;   //输出一个修改信息的菜单 
		cout << "1.姓名" << endl;
		//cout << "2.出生日期" << endl;
		cout << "2.专业" << endl;
		//cout << "4.性别" << endl;
		cout << "3.电话号码" << endl;
		cout << "4.学院" << endl;
		cout << "5.身份证" << endl;
		cout << "6.班级编号" << endl;
		cout << "0.退出修改信息的界面" << endl;
		cout << "请选择要进行的操作：" << endl;
		cin >> d;
		if (d == 0)
			return;
		cout << endl;

		int n = -1;                         //,n用来找到后记录下标 
		for (int i = 0; i < M; i++)            //在传过来的全体学生中查找输入的学号，找到后记录下标，然后跳出循环 
		{
			if (a[i].num == x)
			{
				n = i; break;
			}
		}
		if (n == -1) { cout << "查无此人" << endl; }
		else
		{
			switch (d)
			{
			case 1:cout << "将姓名" << a[n].name << "修改为："; cin >> y; indata(a[n].name, y, a[n].num); a[n].name = y; cout << endl; break;
				//case 2:cout << "将出生日期" << a[n].born << "修改为："; cin >> y; indata(a[n].born, y, a[n].num); a[n].born = y; cout << endl; break;
			case 2:cout << "将专业" << a[n].spe << "修改为："; cin >> y; indata(a[n].spe, y, a[n].num); a[n].spe = y; cout << endl; break;
				//case 4:cout << "将性别" << a[n].sex << "修改为："; cin >> y; indata(a[n].sex, y, a[n].num); a[n].sex = y; cout << endl; break;
			case 3:cout << "将电话号码" << a[n].phone << "修改为："; cin >> y; indata(a[n].phone, y, a[n].num); a[n].phone = y; cout << endl; break;
			case 4:cout << "将学院" << a[n].college << "修改为："; cin >> y; indata(a[n].college, y, a[n].num); a[n].college = y; cout << endl; break;
			case 5:cout << "将身份证" << a[n].id << "修改为：";
				cin >> y;
				if (RID(y) == true)
				{
					indata(a[n].id, y, a[n].num);
					a[n].id = y;
					a[n].born = y.substr(6, 4) + '.' + y.substr(10, 2) + "." + y.substr(12, 2);
					if ((a[n].id[16] - '0') % 2 == 0)//利用身份证号补充性别信息
					{
						a[n].sex = "女";
					}
					else if ((a[n].id[17] - '0') % 2 == 1)
						a[n].sex = "男";
					cout << endl; break;
				}
				else break;
			case 6:cout << "将班级编号" << a[n].class_number << "修改为："; cin >> y; indata(a[n].class_number, y, a[n].num); a[n].class_number = y; cout << endl; break;

			}
			cout << "-----------------------------------" << endl << "修改后的学生信息库为:" << endl;//输出验证 

			PSt(a[n]);
			getfile_cov(a);
			system("cls");
		}
	}
}
void findName(student a[]) {//查找的学生的姓名
	int n = 0;
	ifstream fin;
	string P;
	int jige1 = 0;//有相同字段的学生个数
	int s = 1;
	while (s) {
		cout << "请输入您所要查找的学生的姓名:";
		cin >> P;
		time();
		ofstream outfile("data.txt", ios_base::app);
		if (!outfile) {
			cout << "打开文件失败！" << endl;
		}
		outfile << "查询了有关" << P << "的信息" << endl;
		outfile.close();
		n = ReadStu(a);
		cout << "正在查找..." << endl <<
			"--------------------------" << endl;
		int jige = 0;
		for (int k = 0; k <= n; k++) {
			if (a[k].name == P)
			{
				PSt(a[k]); cout << "--------------------------" << endl;
				jige++;
			}
		}
		if (jige == 0) {
			cout << "在数据库中未查找到姓名为“" << P << "”的学生!" << endl
				<< "正在为您查找姓名中包含“" << P << "”字段的学生..." << endl <<
				"------------------------------------------------------------" << endl;
			for (int k = 0; k <= n; k++) {
				string str = a[k].name;
				string str2;
				std::size_t found = str.find(str2);//无符号整数
				found = str.find(P);
				if (found != std::string::npos) {
					//npos是一个常数，表示size_t的最大值（Maximum value for size_t）
					PSt(a[k]);
					jige1++;
				}
			}
			if (jige1 == 0) {
				cout << "在数据库中未查找到姓名中包含“" << P << "”字段的学生" << endl;
				cout << "------------------------------------------------------------" << endl;
			}
			else {
				cout << "------------------------------------------------------------" << endl << endl;
				cout << "查找完毕!共查找到" << jige1 << "个姓名中包含" << P << "的学生" << endl;
				cout << "------------------------------------------------------------" << endl;
			}
		}
		else {
			cout << endl;
			cout <<
				"--------------------------" << endl << "查找完毕!共查找到" << jige << "个姓名为" << P << "的学生" << endl;
		}
		cout << "是否继续查询姓名" << endl;
		cout << "1.是 0.否" << endl;
		cin >> s;
	}
}
//按班级查找
void findinfor(student a[]) {//根据班级查全部同学信息或全部信息及成绩 
	int n = 0, c = 1, t;
	string m;
	int jige = 0;
	n = ReadStu(a);
	while (c) {
		cout << "请输入您所要查找的学生的班级:";
		cin >> m;
		cout << "【1】查找信息及成绩，【0】查找信息" << endl;
		cin >> t;
		int k = 0;
		if (t == 1) {
			time();
			ofstream outfile("data.txt", ios_base::app);
			if (!outfile) {
				cout << "打开文件失败！" << endl;
			}
			outfile << "查询了班级" << m << "的全部同学信息及成绩" << endl;
			outfile.close();
			for (k = 0; k < n; k++)
				if (a[k].class_number == m) {
					jige++;
					PSt(a[k]);
					cout << "----------------------------------" << endl;
				}
		}
		else {
			time();
			ofstream outfile("data.txt", ios_base::app);
			if (!outfile) {
				cout << "打开文件失败！" << endl;
			}
			outfile << "查询了班级" << m << "的全部同学信息" << endl;
			outfile.close();
			jige = 0;
			for (k = 0; k <= n; k++)
				if (a[k].class_number == m) {
					jige++;
					cout << setiosflags(ios::left)
						<< setw(13) << a[k].num
						<< setw(10) << a[k].name
						<< setw(8) << a[k].sex
						<< setw(20) << a[k].born
						<< setw(30) << a[k].id
						<< setw(19) << a[k].phone
						<< setw(27) << a[k].college
						<< setw(25) << a[k].spe
						<< setw(15) << a[k].class_number << endl;
				}
		}
		if (jige == 0) {
			cout << "在数据库中未查找到班级为" << m << "的学生!";

		}
		cout << "是否继续查找?" << endl << "【1】是，【0】否" << endl;
		cin >> c;
	}
}
//查找某科目的成绩 - 输出符合条件学生的信息
void select1(student a[])
{
	int m = 0;
	m = ReadStu(a);
	string x;//定义输入的那个课程的变量 
	int y;//定义那个输入的分数变量 
	int s = 1;
	while (s) {
		cout << "请输入要查询的课程：";
		cin >> x;
		cout << endl;
		cout << "请输入限制分数：";
		cin >> y;
		int t = 0;//用来判断在全体学生的科目有没有找到这个科目 
		for (int i = 0; i < M; i++)//在全体学生中找 
		{
			if (a[i].num == "0")break;
			for (int j = 0; j < 9; j++)
			{
				if (a[i].cs[j].coursename == x)
				{
					t = 1;
					if (a[i].cs[j].grade >= y)
					{
						cout << a[i].name << "   " << a[i].num << "   " << a[i].class_number << "   " << a[i].cs[j].coursename << "   " << a[i].cs[j].grade << endl;
						cout << "--------------------------------------------" << endl;
					}//这个科目中成绩的大括号
				}//j中找科目的
			}//i中j的大括号
		}//for循环i的大括号
		if (t == 1) {
			cout << "以上就是" << x << "成绩大于" << y << "的所有学生" << endl;
			time();
			ofstream outfile("data.txt", ios_base::app);
			if (!outfile) {
				cout << "打开文件失败！" << endl;
			}
			outfile << "查询了" << x << "成绩大于" << y << "的全部同学" << endl;
			outfile.close();
		}
		if (t == 0)cout << "查无此科目或没有找到" << x << "科目成绩大于等于" << y << "的同学" << endl;
		cout << "是否继续查询" << endl;
		cout << "1.是 0.否" << endl;
		cin >> s;
	}
}//函数的大括号                                            
//查询不及格课程数目
void select2(student a[])
{//从文件读入 
	int m = 0;
	ReadStu(a);
	int b[9] = { 0 };//定义一个放某位同学的不及格课程的下标的数组 
	int x;
	int s = 1;
	while (s) {
		cout << "请输入要查询不及格的课程数目";
		cin >> x;
		int t = 0;
		for (int i = 0; i < M; i++)
		{
			int b[9] = { 0 };//每次循环下一个的同学的时候先让这个记录不及格课程的下标的数组的元素全为0   
			int n = 0;//每次循环的时候记录一位同学的不及格课程数目 
			if (a[i].num == "0")break;
			for (int j = 0; j < 9; j++)
			{
				if (a[i].cs[j].coursename == "#")break;
				if (a[i].cs[j].grade <= 60)
				{
					b[n] = j;
					n++;
				}
			}
			if (n >= x)
			{
				t = 1;//若找到一位同学的不及格课程大于等于输入的指定值，就将t变为1 
				cout << endl;
				PSt(a[i]);
				for (int p = 0; p < 9;)//从b[]数组中获取这位同学不及格课程的下标 
				{
					int c = b[p];
					p++;
					if (b[p] == 0)break;//先输出一个后，因为第一个不及格课程下标有可能是0，再p++，若之后的值为0，说明没有其他不及格的课程了 
				}
				cout << endl;
			}
		}
		if (t == 1) {
			cout << "以上就是不及格科目数目大于等于" << x << "的所有学生";
			cout << endl;
			time();
			ofstream outfile("data.txt", ios_base::app);
			if (!outfile) {
				cout << "打开文件失败！" << endl;
			}
			outfile << "查询了" << x << "不及格课程大于等于" << x << "的全部同学" << endl;
			outfile.close();
		}
		if (t == 0)cout << "没有找到不及格课程数目大于等于" << x << "的学生" << endl;
		cout << "是否继续查询" << endl;
		cout << "1.是 0.否" << endl;
		cin >> s;
	}
}
//统计成绩，由教师操作
void tongjicj(student a[]) {
	int s = 1;
	while (s)
	{
		int f[9] = { 0 };//用来保存九个分数段各自的人数
		string x;
		cout << "请输入要统计的课程：";
		cin >> x;
		int t = 0;//用来判断在全体学生的科目有没有找到这个科目 
		for (int i = 0; i < M; i++)//在全体学生中找 
		{
			for (int j = 0; j < 9; j++)
			{
				if (a[i].cs[j].coursename == "#")
					break;
				if (a[i].cs[j].coursename == x)
				{
					t = 1;
					if (a[i].cs[j].grade >= 95)f[0]++;
					else if (a[i].cs[j].grade >= 90)f[1]++;
					else if (a[i].cs[j].grade >= 85)f[2]++;
					else if (a[i].cs[j].grade >= 80)f[3]++;
					else if (a[i].cs[j].grade >= 75)f[4]++;
					else if (a[i].cs[j].grade >= 70)f[5]++;
					else if (a[i].cs[j].grade >= 65)f[6]++;
					else if (a[i].cs[j].grade >= 60)f[7]++;
					else f[8]++;
				}
			}
		}
		if (t == 0)cout << "查无此科目" << endl;
		else {
			cout << "该课程成绩在95—100之间的学生人数为" << f[0] << endl;
			cout << "该课程成绩在90—94之间的学生人数为" << f[1] << endl;
			cout << "该课程成绩在85—89之间的学生人数为" << f[2] << endl;
			cout << "该课程成绩在80—84之间的学生人数为" << f[3] << endl;
			cout << "该课程成绩在75—79之间的学生人数为" << f[4] << endl;
			cout << "该课程成绩在70—74之间的学生人数为" << f[5] << endl;
			cout << "该课程成绩在65—69之间的学生人数为" << f[6] << endl;
			cout << "该课程成绩在60—64之间的学生人数为" << f[7] << endl;
			cout << "该课程成绩不及格的学生人数为" << f[8] << endl;
			cout << "柱状图如下：" << endl;
			zhuzhuangtu(f);
		}
		cout << "是否继续统计？1.是 0.否" << endl;
		cin >> s;
	}
}
//生成柱状图 - 由 tongjicj() 调用
void zhuzhuangtu(int s[])
{
	int max = -1;
	for (int i = 0; i < 9; i++) {
		if (max < s[i])
			max = s[i];
	}//在传过来的统计好的各个分数段的 数组中，找一个最大值 
	cout << " y/人数" << endl;
	cout << " ∧" << endl;//y轴的箭头 
	for (int i = max + 5; i >= 1; i--)//用双层循环，i控制几行，也是y轴上的数据，从大到小。i是y轴上显示的最大值，
		// i=max+5是为了在max上多5行为了程序的美观 
	{
		if (i >= 10)
			cout << i << "|";//为了使y轴的每根线对齐 
		else cout << i << " |";//如果是10以内的数字就多输出一个空格 
		for (int j = 8; j >= 0; j--)//因为已知了x轴上有9个分段，所以j是每行的第j列
		{
			if (s[j] >= i)//s数组中的数据一个一个和y轴这一行的y的值也就是i进行比较 
				cout << "******";//用******用来形成柱状图 
			else cout << "      ";
			cout << "     ";
		}
		cout << endl;
	}
	cout << "  --------------------------------------------------------------------------------------------------->" << endl;
	cout << "0--不及格     60--64     65--69     70--74     75--79     80--84     85--89     90--94     95--100  x/分数段" << endl;//x轴及x轴上的显示
	for (int i = 8; i >= 0; i--)
	{
		cout << "    " << s[i] << "人    ";
	}
	cout << endl;
}
//按学号查询指定同学全部信息
void search1(student a[]) {
	int s = 1;
	int n = 0;
	string j;
	while (s) {
		int m = 0;
		cout << "请输入要查询学生的学号" << endl;
		cin >> j;
		for (n = 0; n < M; n++) {
			if (a[n].num == "0") break;
			if (a[n].num == j) {
				time();
				ofstream outfile("data.txt", ios_base::app);
				if (!outfile) {
					cout << "打开文件失败！" << endl;
				}
				outfile << "查询了学号" << j << "的全部信息" << endl;
				outfile.close();
				cout << endl << "查询的学生信息为:" << endl;
				PSt(a[n]);
				m = 1;
			}
			if (m == 1) break;
		}
		if (m == 0) cout << "输入的学号不存在" << endl;
		cout << "是否继续查找（1是0否）" << endl;
		cin >> s;
	}
}
//按学号查询该学院全部同学信息
void search2(student a[]) {
	int n = 0;
	int k = 1;
	string j;
	int s = 1;
	while (s) {
		int m = 0;
		cout << "请输入要查询学院的学号" << endl;
		cin >> j;
		for (n = 0; n < M; n++) {
			if (a[n].num == "0") break;
			if (a[n].num.substr(0, 2) == j.substr(0, 2)) {
				m = 1;
				cout << endl << "学院第" << k << "个学生信息为:" << endl;
				cout << setiosflags(ios::left) << setw(13) << a[n].num << setw(10) << a[n].name << setw(8) << a[n].sex << setw(20) << a[n].born << setw(30) << a[n].id << setw(25) << a[n].phone << setw(27) << a[n].college << setw(25) << a[n].spe << setw(15) << a[n].class_number << setw(4) << a[n].allgrade << setw(9) << a[n].cs[0].coursename << setw(3) << a[n].cs[0].grade << setw(9) << a[n].cs[1].coursename << setw(3) << a[n].cs[1].grade << setw(5) << a[n].cs[2].coursename << setw(3) << a[n].cs[2].grade << endl;
				k++;
			}
		}
		if (m == 0)cout << endl << "输入的学院代码不存在" << endl;
		else {
			time();
			ofstream outfile("data.txt", ios_base::app);
			if (!outfile) {
				cout << "打开文件失败！" << endl;
			}
			outfile << "查询了学院代码为" << j << "的全部同学信息" << endl;
			outfile.close();
		}
		cout << "是否继续查找" << endl;
		cout << "1.是 0.否" << endl;
		cin >> s;
	}
}
//按学号查询指定同学全部成绩信息
void search3(student a[]) {
	int n = 0;
	int m = 0;
	string j;
	int s = 1;
	while (s) {
		m = 0;
		cout << "请输入要查询学生的学号" << endl;
		cin >> j;
		for (n = 0; n < M; n++) {
			if (a[n].num == "0") break;
			if (a[n].num == j) {
				cout << "查询的学生" << a[n].name << "的成绩信息为:" << endl;
				cout << setiosflags(ios::left) << setw(9) << a[n].cs[0].coursename << setw(3) << a[n].cs[0].grade << setw(9) << a[n].cs[1].coursename << setw(3) << a[n].cs[1].grade << setw(5) << a[n].cs[2].coursename << setw(3) << a[n].cs[2].grade << endl;
				m = 1;
				break;
			}
		}
		if (m == 0)cout << endl << "输入的学号不存在" << endl;
		else {
			time();
			ofstream outfile("data.txt", ios_base::app);
			if (!outfile) {
				cout << "打开文件失败！" << endl;
			}
			outfile << "查询了学生" << j << "的全部课程成绩" << endl;
			outfile.close();
		}
		cout << "是否继续查询" << endl;
		cout << "1.是 0.否" << endl;
		cin >> s;
	}
}
//按学号查询指定同学指定课程的成绩
void search4(student a[]) {
	int n = 0;
	int r = 0;
	string j;
	int s = 1;
	while (s) {
		r = 0;
		cout << "请输入要查询学生的学号" << endl;
		cin >> j;
		for (n = 0; n < M; n++) {
			if (a[n].num == "0") break;
			if (a[n].num == j) {
				string h;
				cout << "请输入要查询学生的课程" << endl;
				cin >> h;
				int m = 0;
				for (; m < 9; m++) {
					if (a[n].cs[m].coursename == h) {
						cout << "查询的学生" << a[n].name << "的" << a[n].cs[m].coursename << "成绩为" << a[n].cs[m].grade << endl;
						time();
						ofstream outfile("data.txt", ios_base::app);
						if (!outfile) {
							cout << "打开文件失败！" << endl;
						}
						outfile << "查询了学生" << a[n].num << "的" << a[n].cs[m].coursename << "成绩" << endl;
						outfile.close();
						break;
					}
				}
				if (m == 3)cout << endl << "输入的课程不存在" << endl;
				r = 1;
				break;
			}
		}
		if (r == 0)cout << endl << "输入的学号不存在" << endl;
		cout << "是否继续查询" << endl;
		cout << "1.是 0.否" << endl;
		cin >> s;
	}
}
//删除班级
void shanchu(student a[]) {
	int d = 1;
	while (d) {
		int m = 0;
		string x;
		string y;
		int c[5] = { 0 };//记录同一个专业的班级 
		int e = 0;//用来记录已经进入c数组的下一元素的下标 
		int flag2 = 0;//用来判断是否找到输入专业的班级 
		int j = 0;
		int flag3 = 0;
		cout << "请输入要删除班级的专业名称：";
		cin >> x;
		m = ReadStu(a);
		for (int i = 0; i < m; i++)
		{
			if (a[i].num == "0") break;
			if (a[i].spe == x)
			{
				flag2 = 1; //找到这个专业的同学，就相当于找到了班级 
				if (e == 0)
				{
					c[e] = i; e++;
				}
				else
					if (a[i].class_number != a[c[e - 1]].class_number)
					{
						c[e] = i;
						e++;
					}
			}
		}
		if (flag2 == 1)
		{
			cout << "找到以下班级：" << endl;
			for (int i = 0; i < e; i++)
			{
				cout << a[c[i]].class_number << endl;
			}
			cout << "请输入要删除的班级编号:";
			cin >> y;
			int flag1 = 0;
			for (int i = 0; i < M; i++)
			{
				if (a[i].num == "0") break;
				if (a[i].num.substr(0, 8) == y)
				{
					flag1 = 1;
					for (int j = i; j < M; j++)
					{
						if (a[j].num == "0") break;
						else
						{
							a[j] = a[j + 1];
						}
					}//删除就是后一个覆盖前一个
					i--;//因为这个位置的的所有数据都已经变成下一个同学的，所以i--，到上面i++，再看这个下标下的那位同学	
				}
			}
			if (flag1)//如果flag1改变了是1，说明找到了学号前8位是输入的班级编号，也就是说输入的班级编号是正确的 
			{
				cout << "-----------------------------------" << endl << "修改后的学生信息库为:" << endl;//输出验证 
				for (int n = 0; n < M; n++)
				{
					if (a[n].num == "0")   break;
					PSt(a[n]);
					cout << endl;
				}
				getfile_cov(a);
			}
			if (!flag1)
			{
				cout << "输入班级编号错误！" << endl;
			}
		}
		if (flag2 == 0) cout << "没有找到输入专业对应的班级" << endl;
		cout << "是否要继续进行输入专业和班级删除班级操作（1是0否）：";
		cin >> d;
	}
}
//根据学号删除所在班级
void alldelete(student a[]) {
	int s = 1;
	int b = 0;
	while (s) {
		string x;
		cout << "请输入删除班级的学号" << endl;
		cin >> x;
		if (x.length() != 10) {
			cout << "格式错误，请重新输入:" << endl;
			cin >> x;
		}
		ReadStu(a);
		int n = M;
		for (int i = 0; i < n; i++) {
			if (a[i].num == "0") break;
			if (a[i].class_number == x.substr(0, 8)) {
				for (int i = 0; i < M; i++)
				{
					if (a[i].num == "0") break;
					if (a[i].num.substr(0, 8) == x.substr(0, 8))
					{
						for (int j = i; j < M; j++)
						{
							if (a[j].num == "0") break;
							else
							{
								a[j] = a[j + 1];
							}
						}//删除就是后一个覆盖前一个
						i--;//因为这个位置的的所有数据都已经变成下一个同学的，所以i--，到上面i++，再看这个下标下的那位同学	
					}
				}
				cout << "-----------------------------------" << endl << "修改后的学生信息库为:" << endl;//输出验证 
				for (int n = 0; n < M; n++)
				{
					if (a[n].num == "0")   break;
					cout << setiosflags(ios::left)
						<< setw(13) << a[n].num
						<< setw(11) << a[n].name
						<< setw(9) << a[n].sex
						<< setw(19) << a[n].born
						<< setw(32) << a[n].id
						<< setw(19) << a[n].phone
						<< setw(27) << a[n].college
						<< setw(26) << a[n].spe
						<< setw(15) << a[n].class_number << setw(8)
						<< "总成绩:" << setw(4) << a[n].allgrade
						<< setw(6) << "成绩：";
					for (int j = 0; j < 9; j++)
					{
						if (a[n].cs[j].coursename == "#")   break;
						cout << setw(9) << a[n].cs[j].coursename << setw(5) << a[n].cs[j].grade;
					}
					cout << endl;
				}
				getfile_cov(a);
			}
		}
		if (b == 0)
		{
			cout << "未找到该同学所在班级" << endl;
			break;
		}
		cout << "学生信息为：" << endl;
		for (int j = 0; j < M; j++)
		{
			if (a[j].num == "0") break;
			PSt(a[j]);
			cout << endl;
		}
		getfile_cov(a);
	}
}
//按照学号删除指定学生
void xuehao_shan(student a[]) {
	int s = 1;
	int b = 0;
	int i = 0;
	while (s) {
		string x;
		cout << "请输入删除学生的学号" << endl; cin >> x;
		while (x.length() != 10)
		{
			cout << "格式错误，请重新输入:"; cin >> x;
		}
		ReadStu(a);
		for (i = 0; i < M; i++)
		{
			if (a[i].num == "0") break;
			if (a[i].num == x) {
				b = 1;
				for (int j = i; j < M; j++)
				{
					if (a[j].num == "0") break;
					a[j] = a[j + 1];
				}
			}
		}
		if (b == 0) cout << "未找到该同学" << endl;
		else {
			cout << "学生信息为：" << endl;
			for (int j = 0; j < M; j++)
			{
				if (a[j].num == "0") break;
				cout << a[j].num << "  " << a[j].name << "  " << a[j].sex << "  " << a[j].born << "  " << a[j].phone << "  " << a[j].college << "  " << a[j].id << "  " << a[j].class_number << "  " << a[j].allgrade << endl;
				for (int i = 0; i < 9; i++)
				{
					if (a[j].cs[i].grade == 0) break; cout << a[j].cs[i].coursename << "  " << a[j].cs[i].grade << "  ";
					if (a[i].cs[j].coursename == "#")   break;
				}
				cout << endl;
			}
		}
		cout << "是否继续进行按照学号删除？1.是 0.否" << endl;
		cin >> s;
	}
	getfile_cov(a);
}
//按照姓名删除指定学生
void xingming_shan(student a[]) {
	int s = 1;
	while (s)
	{
		int i = 0;
		string j;
		int f[M] = { 0 };//记录下标
		cout << "请输入要删除学生的姓名" << endl;
		cin >> j;
		ReadStu(a);
		int g = 0;
		while (i < M)
		{
			if (a[i].name == "无")
				break;
			if (a[i].name == j)
			{
				f[g] = i; g++;
			}
			i++;
		}
		if (g == 1)
		{
			i = f[0];
			for (int j = i; j < M; j++)
			{
				if (a[j].num == "0")
					break;
				a[j] = a[j + 1];
			}
		}
		if (g > 1) {
			for (int u = 0; u < g; u++) {
				int n = f[u];
				int r = u + 1;
				cout << "第" << r << "个同名学生的学号为" << a[n].num << endl;
			}
			cout << "请输入选择删除第几个同名学生" << endl;
			int r;
			cin >> r;
			i = f[--r];
			for (int j = i; j < M; j++)
			{
				if (a[j].num == "0")
					break;
				else
					a[j] = a[j + 1];
			}
		}
		if (g == 0) cout << "未找到该同学" << endl;
		cout << "学生信息为：" << endl;
		for (int j = 0; j < M; j++)
		{
			if (a[j].num == "0") break;
			PSt(a[j]);
			cout << endl;
		}
		getfile_cov(a);
		cout << "是否继续进行按照姓名删除？1.是 0.否" << endl;
		cin >> s;
	}
}
//按照总成绩排序
void sort(student a[]) {
	string j;
	double f[M] = { 0 }, s[M] = { 0 };
	int n = 0;
	double t = 0;
	int num = ReadStu(a);
	for (n = 0; n < num; n++)
	{
		f[n] = a[n].allgrade;
		s[n] = n;
	}
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < n - 1 - j; i++) {
			if (f[i] < f[i + 1]) {
				t = f[i]; f[i] = f[i + 1]; f[i + 1] = t;
				t = s[i]; s[i] = s[i + 1]; s[i + 1] = t;
			}
			if (f[i] == f[i + 1] && a[i].num > a[i].num)
			{
				t = f[i]; f[i] = f[i + 1]; f[i + 1] = t;
				t = s[i]; s[i] = s[i + 1]; s[i + 1] = t;
			}
		}
	for (int i = 0; i < n - 1; i++) {
		if (f[i] == f[i + 1] && a[(int)s[i]].num > a[(int)s[i + 1]].num) {
			t = f[i]; f[i] = f[i + 1]; f[i + 1] = t;
			t = s[i]; s[i] = s[i + 1]; s[i + 1] = t;
		}
	}
	for (int j = 0; j < n; j++) {
		cout << a[(int)s[j]].name << "\t" << a[(int)s[j]].num << "   " << f[j] << endl;
	}

}
//输入班级后按总成绩降序输出学生信息
void sort01(student a[]) {
	string j;
	string clnum;
	cout << "请输入您所要查询的班级的编号:" << endl;
	cin >> clnum;
	double f[M] = { 0 }, s[M] = { 0 };
	int n = 0;
	double t = 0;
	int num = ReadStu(a);
	for (n = 0; n < num; n++)
	{
		f[n] = a[n].allgrade;
		s[n] = n;
	}
	n++;
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < n - 1 - j; i++) {
			if (f[i] < f[i + 1]) {
				t = f[i]; f[i] = f[i + 1]; f[i + 1] = t;
				t = s[i]; s[i] = s[i + 1]; s[i + 1] = t;
			}
			if (f[i] == f[i + 1] && a[i].num > a[i].num)
			{
				t = f[i]; f[i] = f[i + 1]; f[i + 1] = t;
				t = s[i]; s[i] = s[i + 1]; s[i + 1] = t;
			}
		}
	for (int i = 0; i < n - 1; i++) {
		if (f[i] == f[i + 1] && a[(int)s[i]].num > a[(int)s[i + 1]].num) {
			t = f[i]; f[i] = f[i + 1]; f[i + 1] = t;
			t = s[i]; s[i] = s[i + 1]; s[i + 1] = t;
		}
	}
	cout << "---------------------------------------------" << endl;
	cout << clnum << "班同学的信息如下: (排序方式: 按总成绩降序)" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int mc = 0;//班级名次
	cout << setiosflags(ios::left)
		<< setw(12) << "学号"
		<< setw(11) << "姓名"
		<< setw(6) << "排名"
		<< setw(9) << "总成绩"
		<< setw(9) << "性别"
		<< setw(19) << "出生日期"
		<< setw(32) << "身份证号码"
		<< setw(19) << "联系电话"
		<< setw(27) << "学院"
		<< setw(26) << "专业"
		<< setw(26) << "单科成绩"
		//<< setw(15) << a[s[j]].class_number
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int j = 0; j < n - 1; j++) {
		if (a[(int)s[j]].class_number == clnum) {
			mc++;
			cout// << setiosflags(ios::left)
				<< setw(12) << a[(int)s[j]].num
				<< setw(11) << a[(int)s[j]].name
				<< setw(6) << mc
				<< setw(9) << a[(int)s[j]].allgrade
				<< setw(9) << a[(int)s[j]].sex
				<< setw(19) << a[(int)s[j]].born
				<< setw(32) << a[(int)s[j]].id
				<< setw(19) << a[(int)s[j]].phone
				<< setw(27) << a[(int)s[j]].college
				<< setw(26) << a[(int)s[j]].spe
				//<< setw(15) << a[s[j]].class_number
				<< a[(int)s[j]].cs[0].coursename << ":"
				<< setw(9) << a[(int)s[j]].cs[0].grade
				<< a[(int)s[j]].cs[1].coursename << ":"
				<< setw(9) << a[(int)s[j]].cs[1].grade
				<< a[(int)s[j]].cs[2].coursename << ":"
				<< setw(9) << a[(int)s[j]].cs[2].grade
				<< endl;
		}
	}
}
//按专业指定课程成绩降序 
void zysort(student a[]) {
	string j;
	double f[M] = { 0 }, s[M] = { 0 };
	double x;
	int m = 0;
	int t = 0;
	cout << "请输入专业名称：" << endl;
	cin >> j;
	for (int p = 0; p < M; p++) {
		if (a[p].spe == j)
		{
			f[t] = p;
			t++;
		}
	}
	cout << "请输入课程名称：" << endl;
	cin >> j;
	for (m = 0; m < 5; m++) {
		if (a[(int)f[0]].cs[m].coursename == j) break;

	}
	for (int p = 0; p < t; p++) {
		s[p] = a[(int)f[p]].cs[m].grade;
	}

	for (int j = 0; j < t; j++)
		for (int i = 0; i < t - j; i++) {
			if (s[i] < s[i + 1]) {
				x = s[i]; s[i] = s[i + 1]; s[i + 1] = x;
				x = f[i]; f[i] = f[i + 1]; f[i + 1] = x;
			}
		}
	for (int j = 0; j < t; j++) {
		cout << a[(int)f[j]].name << a[(int)f[j]].num << "   " << a[(int)f[j]].cs[m].grade << endl;
	}
}
//管理员浏览学生基本信息
void allliulan(student a[]) {
	cout << "学生信息为：" << endl;
	for (int j = 0; j < M; j++)
	{
		if (a[j].name == "无")
			break;
		cout << "------------------------------------" << endl;
		PSt(a[j]);
		cout << "------------------------------------" << endl;
	}
	system("pause");
}
//管理员添加用户信息
void adduser(user c[]) {
	system("cls");
	string l, x;
	int a;
	cout << "----------------" << endl;
	cout << "是否添加用户：【1】确定 【0】取消" << endl;
	cout << "----------------" << endl;
	cin >> a;
	int s = 1;
	while (a) {
		int i = 0;
		cout << setw(17) << "请输入用户账号（学生为学号，其他为电话号）: ";
		cin >> c[i].ac;
		cout << "请输入姓名: ";
		cin >> c[i].name;
		cout << "请输入密码: ";
		cin >> c[i].pw;
		cout << "请输入性别: ";
		cin >> c[i].sex;
		cout << "请输入身份:";
		cin >> c[i].idt;
		cout << "请输入年龄: ";
		cin >> c[i].age;
		getUser(c[i]);
		cout << "是否继续添加：" << endl;
		cout << "【1】是 【0】否" << endl;
		cin >> a;
	}
}
//学生浏览个人信息 
void liulanxx(string b, int i, student a[]) {
	for (i = 0; i < M; i++)
	{
		if (a[i].num == b)
		{
			cout << "您的基本信息为:" << endl;
			cout << setiosflags(ios::left) << setw(13) << a[i].num << setw(10) << a[i].name << setw(8) << a[i].sex << setw(20) << a[i].born << setw(30) << a[i].id << setw(25) << a[i].phone << setw(27) << a[i].college << setw(25) << a[i].spe << setw(15) << a[i].class_number << endl;
			break;
		}
	}
	system("pause");
}
//学生浏览个人成绩
void liulancj(string b, int i, student a[]) {
	ReadStu(a);
	for (int j = 0; j < M; j++) {
		if (a[j].num == b) {
			cout << b;
			cout << "您的成绩信息为:" << endl;
			cout << setiosflags(ios::left) << "总分:  " << setw(6) << a[j].allgrade << setw(7) << a[j].cs[0].coursename << setw(5) << a[j].cs[0].grade << setw(9) << a[j].cs[1].coursename << setw(5) << a[j].cs[1].grade << setw(5) << a[j].cs[2].coursename << setw(5) << a[j].cs[2].grade << endl;
			break;
		}
	}
	system("pause");
}
//用户浏览用户信息
void userliulan(user d[]) {
	int i = 0;
	i = ReadUser(d);
	for (int j = 0; j < i - 1; j++)
	{
		if (d[j + 1].pw == "0")break;
		cout << setiosflags(ios::left) << setw(13) << d[j].ac << setw(10) << d[j].name << setw(10) << d[j].pw << setw(6) << d[j].sex << setw(7) << d[j].idt << setw(4) << d[j].age << endl;
	}
	system("pause");
}
//实现输入给定用户账号，修改指定用户的部分信息
void modifyYH(user c[]) {
	ifstream fp;
	user d[M];
	int leix = 1;
	cout << "请输入您所要修改的用户的类型:	" << endl;
	cout << "	1.教师" << endl;
	cout << "	2.学生" << endl;
	int num = ReadUser(d);
	cin >> leix;
	if (leix == 1) {
		fp.open("teacherm.txt");
	}
	else {
		fp.open("studentm.txt");
	}
	int i = 0;
	while (fp.peek() != EOF)
	{
		fp >> c[i].ac
			>> c[i].name
			>> c[i].pw
			>> c[i].sex
			>> c[i].idt
			>> c[i].age;
		i++;
	}//读取学生或老师信息
	cout << "-------------可修改的的信息如下-------------" << endl;   //输出一个修改信息的菜单 
	cout << "		1.姓名" << endl;
	cout << "		2.密码" << endl;
	cout << "		3.性别" << endl;
	cout << "		4.年龄" << endl;
	cout << "		0.退出该界面" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "请选择您要修改的信息类型：" << endl;
	int d1 = 0;
	cin >> d1;
	cout << endl;
	string y;
	while (d1)
	{
		cout << "请输入您要修改的用户的账号:";//做出提示 
		string x;
		cin >> x;                           //输入字符串学号 
		int n = -1;                         //,n用来找到后记录下标 
		for (int i = 0; i < M; i++)            //在传过来的全体学生用户中查找输入的学号，找到后记录下标，然后跳出循环 
		{
			if (c[i].ac == x) {
				n = i; break;
			}
		}
		if (n == -1) { cout << "未查找到您所输入的用户" << endl; }
		else
		{
			switch (d1)
			{
			case 1:cout << "该用户原来的姓名信息为:" << c[n].name << ". 请输入现在要修改为的姓名信息：";
				cin >> y; c[n].name = y; cout << endl;
				for (int v = 0; v < M; v++)
				{
					if (d[v].ac == x)
						d[v].name = y;
				}break;
			case 2:cout << "该用户原来的密码信息为" << c[n].pw << ". 请输入现在要修改为的密码信息：";
				cin >> y; c[n].pw = y; cout << endl;
				for (int v = 0; v < M; v++)
				{
					if (d[v].ac == x)
						d[v].pw = y;
				}break;
			case 3:cout << "该用户原来的性别信息为" << c[n].sex << ". 请输入现在要修改为的性别信息：";
				cin >> y; c[n].sex = y; cout << endl;
				for (int v = 0; v < M; v++)
					if (d[v].ac == x)
						d[v].sex = y;
				break;
			case 4:cout << "该用户原来的年龄信息为" << c[n].age << ". 请输入现在要修改为的年龄信息：";
				cin >> y;  c[n].age = y; cout << endl;
				for (int v = 0; v < M; v++)
					if (d[v].ac == x)	d[v].age = y;
				break;
			}
			cout << endl << "修改成功! 修改后的用户信息库如下" << endl << "-----------------------------------------------------------------------------------" << endl;
			for (int j = 0; j < M; j++)
			{
				if (c[j].pw == "#")   break;
				cout << setiosflags(ios::left)
					<< setw(13) << c[j].ac
					<< setw(10) << c[j].name
					<< setw(16) << c[j].pw
					<< setw(6) << c[j].sex
					<< setw(7) << c[j].idt
					<< setw(4) << c[j].age << endl;
			}
			cout << "-----------------------------------------------------------------------------------" << endl;
			cout << endl << "请问是否要保存修改后的数据库信息(1为是，0为否)请输入操作:" << endl;
			int z;
			cin >> z;
			if (z)
			{
				if (leix == 1) {
					ofstream outfile("teacherm.txt");
					if (!outfile)
					{
						cout << "失败！" << endl;
						return;
					}
					for (int i = 0; i < M; i++)
					{
						if (c[i].pw == "#")   break;
						outfile << setiosflags(ios::left) << setw(13) << c[i].ac;
						outfile << setw(10) << c[i].name;
						outfile << setw(10) << c[i].pw;
						outfile << setw(6) << c[i].sex;
						outfile << setw(7) << c[i].idt;
						outfile << setw(4) << c[i].age;
						outfile << endl;
					}
					outfile.close();
					getUserc(d);
				}
				else {
					ofstream outfile("studentm.txt");//需要覆盖
					if (!outfile)
					{
						cout << "失败！" << endl;
						return;
					}
					for (int i = 0; i < M; i++)
					{
						if (c[i].pw == "#")   break;
						outfile << setw(13) << c[i].ac;
						outfile << setw(10) << c[i].name;
						outfile << setw(10) << c[i].pw;
						outfile << setw(6) << c[i].sex;
						outfile << setw(7) << c[i].idt;
						outfile << setw(4) << c[i].age;
						outfile << endl;
					}
					outfile.close();
					getUserc(d);
				}
				cout << "------------修改信息已保存成功！-----------------" << endl;
			}
		}
		cout << "退出该模块请输入数字 0, 继续进行用户的信息修改请输入下列信息类型的编号" << endl;
		cout << "-------------------------------" << endl;   //输出一个修改信息的菜单 
		cout << "		1.姓名" << endl;
		cout << "		2.密码" << endl;
		cout << "		3.性别" << endl;
		cout << "		4.年龄" << endl;
		cout << "                0.退出该模块" << endl;
		cout << "-------------------------------" << endl;
		cout << "请选择您所要执行的操作：" << endl;
		cin >> d1;
	}
}
//按照账号删除指定用户 - 未验证
void deleteYH(user c[]) {
	ifstream fp;
	int leix = 1;
	cout << "请输入您所要删除的用户的类型:	" << endl;
	cout << "	1.教师" << endl;
	cout << "	2.学生" << endl;
	cin >> leix;
	if (leix == 1) {
		fp.open("teacherm.txt");
	}
	else {
		fp.open("studentm.txt");
	}
	int i = 0;
	while (fp.peek() != EOF)
	{
		fp >> c[i].ac
			>> c[i].name
			>> c[i].pw
			>> c[i].sex
			>> c[i].idt
			>> c[i].age;
		i++;
	}
	user d[M];
	int num = ReadUser(d);
	int s = 1;
	int mm = 0;
	while (s) {
		string x;
		cout << "请输入所要删除的用户的账号" << endl;
		cin >> x;
		int n = M;
		for (i = 0; i < M; i++)
		{
			if (c[i].ac == "#")
				break;
			if (c[i].ac == x) {
				mm = 1;
				for (int j = i; j < n; j++)
				{
					if (c[j].ac == "#") break;
					c[j] = c[j + 1];
				}
				n--;
				break;
			}
		}
		for (i = 0; i < M; i++)
		{
			if (d[i].ac == "#")
				break;
			if (d[i].ac == x)
			{
				for (int j = i; j < n; j++)
				{
					if (d[j].ac == "#") break;
					d[j] = d[j + 1];
				}
			}
		}
		if (mm == 0) cout << "未找到该用户" << endl;
		else {
			cout << "已删除账号为“" << x << "”的用户,删除账号为“" << x << "”的用户后的信息库如下" << endl << "-----------------------------------------------------------------------------------" << endl;
			for (int j = 0; j < M; j++)
			{
				if (c[j].pw == "#")   break;
				cout << setiosflags(ios::left)
					<< setw(13) << c[j].ac
					<< setw(10) << c[j].name
					<< setw(10) << c[j].pw
					<< setw(6) << c[j].sex
					<< setw(7) << c[j].idt
					<< setw(4) << c[j].age;
				cout << endl;
			}
			cout << "-----------------------------------------------------------------------------------" << endl;
		}
		int z;
		cout << endl << "您是否要保存当前的数据库信息(1为是，0为否)请输入操作:" << endl;
		cin >> z;
		if (z) {
			if (leix == 1) {
				ofstream outfile("teacherm.txt");
				if (!outfile) {
					cout << "失败！" << endl;
					return;
				}
				for (int i = 0; i < M; i++) {
					if (c[i].pw == "#")   break;
					outfile << setw(13) << c[i].ac;
					outfile << setw(10) << c[i].name;
					outfile << setw(16) << c[i].pw;
					outfile << setw(6) << c[i].sex;
					outfile << setw(7) << c[i].idt;
					outfile << setw(4) << c[i].age;
					outfile << endl;
				}
				outfile.close();
				getUserc(d);
			}
			else {
				ofstream outfile("studentm.txt");
				if (!outfile) {
					cout << "失败！" << endl;
					return;
				}
				for (int i = 0; i < M; i++) {
					if (c[i].pw == "#")   break;
					outfile << setw(13) << c[i].ac;
					outfile << setw(10) << c[i].name;
					outfile << setw(16) << c[i].pw;
					outfile << setw(6) << c[i].sex;
					outfile << setw(7) << c[i].idt;
					outfile << setw(4) << c[i].age;
					outfile << endl;
				}
				outfile.close();
				getUserc(d);
			}
			cout << "-----------------------------" << endl << "修改信息已保存成功！" << endl;
			cout << endl << "-------------------------------------------------------------" << endl;
			cout << "信息库保存成功！" << endl << "-------------------------------------------------------" << endl;
		}
		cout << "您是否要继续进行删除操作？(1.是 0.否)请输入操作:" << endl;
		cin >> s;
	}

}
//注册用户 - 未增加 studentm.txt、和teacherm.txt 与用户信息同步
void enroll(user b[])
{
	system("cls");
	string x;
	int s = 1;
	int m;
	cout << "----------------" << endl;
	cout << "欢迎注册新用户！" << endl;
	cout << "----------------" << endl;
	cout << "请输入注册账号（学生为学号，其他为电话号）:";
	cin >> x;
	for (int i = 0; i < M; i++) {
		if (b[i].ac == x) {
			s = 3;
			m = i;
			cout << "已有该账号，要修改密码吗？（1是0否）" << endl;
			int t = 0;
			cin >> t;
			while (t) {
				cout << "请输入密码:" << endl;
				cin >> b[m].pw;
				s = 0;
				getUserc(b);
				if (b[m].idt == "老师")
				{

				}
				if (b[m].idt == "学生")
				{

				}
				cout << "密码修改成功！";
				t = 0;
				return;
			}
		}
	}
	while (s == 3) {//没有找到该账号
		//调用管理员添加用户信息
		adduser(b);
	}
}

/*菜单*/
//信息录入菜单
void getmenu1() {
	cout << "请选择您此次录入的方式:" << endl;
	cout << "	1.手动输入学生信息" << endl;
	cout << "	2.用文件导入" << endl;
}
//成绩录入菜单
void grademenu(student a[]) {
	cout << endl << "是否要进行成绩录入操作（1是0否）：";
	int e; cin >> e;
	while (e) {
		cout << "1.某位同学的某门成绩的录入" << endl;
		//cout << "2.某门成绩的录入" << endl;
		cout << "0.退出成绩录入" << endl;
		cout << "请输入要进行的操作：";
		cout << endl;
		int g;
		cin >> g;
		switch (g) {
		case 1:getgrade1(a); break;
			//case 2:getgrade2(a);
			/*{
				text(a);
				cout << endl << "是否要进行成绩录入操作（1是0否）：";
				cin >> e; break;
			}*/
		default: e = 0;
		}
	}
}
//信息录入菜单
void getmenu3(student a[]) {
	cout << endl << " 请选择您想要执行的操作:" << endl;
	cout << "	1.录入学生基本信息" << endl;
	cout << "	0.其它操作" << endl;
	int n;
	cin >> n;
	while (n) {
		getmenu1();
		int m;
		cin >> m;
		switch (m) {
		case 1:setBasic1(a); break;
		case 2:setBasic2(a); break;
		}
		cout << "---------------------------------" << endl;
		cout << endl << "请问您是否要继续进行基本信息的录入:" << endl;
		cout << "	是, 请输入数字 1" << endl;
		cout << "	否, 请输入数字 0" << endl;
		cin >> n;
	}
}
//按学号导出信息
void getmenu2(student a[]) {
	int c;
	int n;
	string m;
	cout << "【1】单个保存" << endl << "【2】批量保存" << endl << "【0】取消" << endl;
	cout << "请选择：" << endl;
	cin >> c;
	if (c == 1) {
		system("cls");
		cout << "请输入要保存的学号:" << endl;
		cin >> m;
		getfile(a, m);
		for (int i = 1; i < M; i++) {
			cout << "是否继续保存?" << endl << "【1】是，【0】否" << endl;
			cin >> n;
			if (n) {
				cout << "请输入要保存的学号:" << endl;
				cin >> m;
				getfile(a, m);
			}
			else break;
		}
	}
	else {
		if (c == 2)  allgetfile(a);
		else  system("cls");
	}
}
//批量修改菜单 
void momenu(student a[]) {
	system("cls");
	int n = 1;
	while (n) {
		cout << "请选择您所要批量修改的信息类型:" << endl;
		cout << "	1.专业名称" << endl;
		cout << "	2.学院名称" << endl;
		cout << "	3.班级编号" << endl;
		cout << "	4.课程名称" << endl;
		int flag = 0;
		cin >> flag;
		modification1(a, flag);
		cout << "是否继续批量修改:" << endl;
		cout << "  1.是" << endl;
		cout << "  0.否" << endl;
		cin >> n;
		cout << "---------------------------------" << endl;
	}
}
//修改成绩菜单
void nummenu(student a[]) {
	system("cls");
	int n;
	cout << "请选择修改成绩方式:" << endl;
	cout << "1.按学号修改全部课程成绩" << endl;
	cout << "2.按学号修改指定课程成绩" << endl;
	cout << "3.按姓名修改指定课程成绩" << endl;
	cout << "0.退出" << endl;
	cin >> n;
	switch (n) {
	case 1:num_mod1(a); break;
	case 2:num_mod2(a); break;
	case 3:num_mod3(a); break;
	}
}
//查询指定学生信息菜单
void numfind(student a[]) {
	int n = 1;
	int i;
	while (n) {
		system("cls");
		cout << "请选择查询内容：" << endl;
		cout << "1.查询指定同学全部信息" << endl;
		cout << "2.查询指定学院全部同学信息" << endl;
		cout << "3.查询指定同学全部成绩信息" << endl;
		cout << "4.查询指定同学指定课程的成绩" << endl;
		cout << "5.退出此界面" << endl;
		cin >> i;
		switch (i) {
		case 1: search1(a); break;
		case 2: search2(a); break;
		case 3: search3(a); break;
		case 4: search4(a); break;
		case 5: n = 0; break;
		}
	}
}
//查询菜单 - 包括查询指定学生信息
void findmenu(student a[]) {
	int m = 1;
	while (m) {
		system("cls");
		cout << "请选择查询内容" << endl;
		cout << "1.按班级查全部同学信息" << endl;
		//cout << "2.使用某通讯公司手机同学信息" << endl;
		cout << "2.按姓名查找同学信息" << endl;
		cout << "3.按学号查找同学信息" << endl;
		cout << "4.成绩大于指定值的同学信息" << endl;
		cout << "5.不及格课程大于指定值的全部同学信息及不及格课程及成绩" << endl;
		cout << "0.退出此界面" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1: findinfor(a); break;
			//case 2: phfound(a); break;
		case 2: findName(a); break;
		case 3: numfind(a); break;
		case 4: select1(a); break;
		case 5: select2(a); break;
		case 0: m = 0; break;
		}
	}
}
//成绩统计菜单 
void cjmenu(student a[]) {
	int m = 1;
	while (m) {
		system("cls");
		cout << "请选择查询内容" << endl;
		cout << "1.成绩大于指定值的同学信息" << endl;
		cout << "2.不及格课程大于指定值的全部同学信息及不及格课程及成绩" << endl;
		cout << "3.统计指定课程各分数段的人数" << endl;
		cout << "0.退出此界面" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1: select1(a); break;
		case 2: select2(a); break;
		case 3: tongjicj(a); break;
		case 0: m = 0; break;
		}
	}
}
//删除菜单
void deletemenu(student a[]) {
	int n = 1;
	while (n) {
		system("cls");
		cout << "以下是删除的相关操作：" << endl;
		cout << "1.按照姓名删除指定学生信息" << endl;
		cout << "2.按照学号删除指定学生信息" << endl;
		cout << "3.按照学号信息删除全班同学信息" << endl;
		cout << "4.输入专业和班级信息，根据学号删除本班全部同学信息" << endl;
		cout << "0.退出删除信息操作" << endl;
		cout << "请输入要进行的删除操作:" << endl;
		cin >> n;
		switch (n) {
		case 1: xingming_shan(a); break;
		case 2: xuehao_shan(a); break;
		case 3: alldelete(a); break;
		case 4: shanchu(a); break;
			ReadStu(a);
		}
	}
}
//排序菜单
void sortmenu(student a[]) {
	int n = 1;
	while (n) {
		system("cls");
		cout << "以下是排序的相关操作：" << endl;
		cout << "1.按输入班级按总成绩降序输出学生基本信息与成绩 " << endl;
		cout << "2.按专业输出给定课程成绩降序输出学生基本信息与成绩 " << endl;
		cout << "3.按总成绩降序排序总成绩相同时按照学号升序排列 " << endl;
		cout << "0.退出排序操作 " << endl;
		cout << "请输入要进行的排序操作:";
		cin >> n;
		switch (n) {
		case 1: sort01(a); system("pause"); break;
		case 2: zysort(a); system("pause"); break;
		case 3: sort(a); system("pause"); break;
		}
	}
}
//管理员菜单
void guanliyuanmenu(user b[], user c[], user d[], int i, student a[]) {

	int n = 0;
	int s = 1;
	int m;
	while (s)
	{
		system("cls");
		cout << "以下是您相关的操作权限：" << endl;
		cout << "1.学生基本信息的添加" << endl;
		cout << "2.学生基本信息的删除" << endl;
		cout << "3.学生基本信息的批量修改" << endl;
		cout << "4.学生基本信息的部分修改" << endl;
		cout << "5.学生基本信息的浏览" << endl;
		cout << "6.用户的添加" << endl;
		cout << "7.用户的修改" << endl;
		cout << "8.用户的删除" << endl;
		cout << "9.所有用户信息的浏览" << endl;
		cout << "0.退出操作" << endl;
		cout << "请输入要进行的操作:" << endl;
		cin >> m;
		switch (m) {
		case 1: getmenu3(a); break;
		case 2: deletemenu(a); break;
		case 3: momenu(a); break;
		case 4: modify1(a); break;
		case 5: allliulan(a); break;
		case 6: adduser(c); break;
		case 7:  modifyYH(c); break;// 调用用户修改的函数 
		case 8: deleteYH(c); break;//调用用户删除的函数
		case 9: userliulan(d); break;//调用用户浏览的函数 
		case 0: n = 0; s = 0; break;
		}
		if (s != 0) {
			cout << "是否再次进入操作权限？【1】是，【0】否" << endl;
			cin >> s;
		}
	}
}
//教师操作菜单 
void jiaoshimenu(student a[])
{
	int n = 1;
	while (n)
	{
		system("cls");
		cout << "以下是您相关的操作权限：" << endl;
		cout << "1.学生成绩录入" << endl;
		cout << "2.学生成绩修改" << endl;
		cout << "3.学生成绩统计" << endl;
		cout << "4.学生成绩排序" << endl;
		cout << "5.学生基本信息的查询" << endl;
		cout << "0.退出操作" << endl;
		cout << "请输入要进行的操作:" << endl;
		cin >> n;
		switch (n) {
		case 1: grademenu(a); break;
		case 2: nummenu(a); break;
		case 3: cjmenu(a); break;
		case 4: sortmenu(a); break;
		case 5: findmenu(a); break;
		case 0: n = 0; break;
		}
	}
}
//学生操作菜单
void xueshengmenu(user b[], int i, student a[])
{
	int n = 1;

	system("cls");
	cout << "以下是您相关的操作权限：" << endl;
	cout << "1.本人信息浏览" << endl;
	cout << "2.本人成绩浏览" << endl;
	cout << "0.退出操作" << endl;
	cout << "请输入要进行的操作:" << endl;
	cin >> n;
	switch (n) {
	case 1:liulanxx(b[i].ac, i, a); break;
	case 2:liulancj(b[i].ac, i, a); break;
	case 0: n = 0; break;
	}
}
//登录界面
void login(user b[], user c[], user d[], student a[]) {
	string x, y;
	int p;
	int i = 0;
	system("cls");
	cout << "------------------" << endl;
	cout << "欢迎进入登录界面！" << endl;
	cout << "------------------" << endl;
	int s = 0;
	while (s == 0)
	{
		cout << "请输入账号:";
		cin >> x;
		int m = 0;
		for (i = 0; i < M; i)
		{
			if (b[i].pw == "#")
				break;
			if (b[i].ac != x)
				i++;
			else if (b[i].ac == x) {
				s = 1;
				cout << "请输入密码:";
				cin >> y;
			log:				while (b[i].pw == y) {
				s = 2;
				if (b[i].idt == "管理员")
				{
					guanliyuanmenu(b, c, d, i, a);//调用管理员菜单 
					return;
				}
				if (b[i].idt == "老师")
				{
					jiaoshimenu(a);//调用老师菜单 
					return;
				}
				if (b[i].idt == "学生")
				{
					xueshengmenu(b, i, a);//调用学生菜单
					return;
				}
			}
			if (b[i].pw != y && m < 3)
			{
				cout << "密码错误，请重新输入：" << endl;
				cin >> y;
				if (b[i].pw == y)
					goto log;
				m++;
			}
			if (m >= 3)
			{
				cout << "密码错误！" << endl;
				s = 0;
				break;
			}
			}
		}
		if (s == 0) {
			cout << "未找到该用户，请核对账号是否输入正确或注册账号" << endl;
			cout << "【1】重新输入" << endl;
			cout << "【0】注册账号" << endl;
			cin >> p;
			if (!p) {
				enroll(b);
				return;
			}//调用注册函数
		}
	}
}
