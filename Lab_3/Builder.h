#pragma once
#include <string>
#include <iostream>

class Article
{
public:
	Article();
	void Print();
	std::string text;
};

class ArticleWriter
{

public:
	virtual void CreateArticle() = 0;
	virtual void WriteTitle() = 0;
	virtual void WriteAnnotation() = 0;
	virtual void WriteBody() = 0;
	virtual void WriteReferences() = 0;
	virtual Article* GetResult() = 0;
};

class ResearchArticleWriter : public ArticleWriter
{

private:

	Article* researchArticle;
public:
	ResearchArticleWriter();
	void CreateArticle();
	void WriteTitle();
	void WriteAnnotation();
	void WriteBody();
	void WriteReferences();
	Article* GetResult();
	~ResearchArticleWriter();
};

class ReviewArticleWriter : public ArticleWriter
{
private:
	Article* reviewArticle;
public:
	ReviewArticleWriter();
	void CreateArticle();
	void WriteTitle();
	void WriteAnnotation();
	void WriteBody();
	void WriteReferences();
	Article* GetResult();
	~ReviewArticleWriter();
};

class Director
{
private:
	ArticleWriter* writer;
public:
	Director(ArticleWriter* inputWriter);
	void Construct();
	void ChangeWriter(ArticleWriter* inputWriter);

};

void RunBuilder();
