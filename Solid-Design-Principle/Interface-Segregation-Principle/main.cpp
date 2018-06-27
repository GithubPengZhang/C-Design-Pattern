#include <iostream>
using namespace std;

struct Document {};

//struct IMachine
//{
//	virtual void print(Document &doc) = 0;
//	virtual void scan(Document &doc) = 0;
//	virtual void fax(Document &doc) = 0;
//};

//struct MFP : IMachine
//{
//	virtual void print(Document &doc) override
//	{
//		throw std::logic_error("The method or operation is not implemented.");
//	}
//
//
//	virtual void scan(Document &doc) override
//	{
//		throw std::logic_error("The method or operation is not implemented.");
//	}
//
//
//	virtual void fax(Document &doc) override
//	{
//		throw std::logic_error("The method or operation is not implemented.");
//	}
//};
//
//
//struct Scanner : IMachine
//{
//	virtual void print(Document &doc) override
//	{
//		throw std::logic_error("The method or operation is not implemented.");
//	}
//
//
//	virtual void scan(Document &doc) override
//	{
//		throw std::logic_error("The method or operation is not implemented.");
//	}
//
//
//	virtual void fax(Document &doc) override
//	{
//		throw std::logic_error("The method or operation is not implemented.");
//	}
//};

struct IPrinter
{
	virtual void print(Document &doc) = 0;
};

struct IScanner
{
	virtual void scan(Document &doc) = 0;
};

struct IFax
{
	virtual void fax(Document &doc) = 0;
};

struct Printer : IPrinter
{
	virtual void print(Document &doc) override
	{
		cout << "Print document" << endl;
	}
};

struct Scanner : IScanner
{
	virtual void scan(Document &doc) override
	{
		cout << "Scanner document" << endl;
	}
};

struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine
{
	IPrinter& printer;
	IScanner& scanner;

	Machine(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {}

	virtual void print(Document &doc) override
	{
		printer.print(doc);
	}


	virtual void scan(Document &doc) override
	{
		scanner.scan(doc);
	}

};

int main()
{
	Document objDoc;
	Printer objPrinter;
	Scanner objScanner;
	Machine objMachine(objPrinter, objScanner);
	objMachine.print(objDoc);
	objMachine.scan(objDoc);


	return 0;
}