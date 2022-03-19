#include "BookPackage.h"

vector<string>BookPackageWord{ "编号","标题","作者","出版社","定价","状态","是否可借","图书所在位置","总数量","剩余数量","所包含的书" };//字段，方便打印



//// 显示当前书籍种类的信息
//void BookPackage::display()
//{
//    // TODO: 在此处添加实现代码.
//}

void BookPackage::borrow()
{
	if (RemainingNumber>0)
	{
		for (Book &temp_book:P_Books)
		{

		}
	}
}
