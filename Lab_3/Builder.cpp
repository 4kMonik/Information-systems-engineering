#include "pch.h"
#include "Builder.h"


Article::Article()
{
	text = std::string("");
}

void Article::Print()
{
	std::cout << text;
}

ResearchArticleWriter::ResearchArticleWriter()
{
	researchArticle = nullptr;
}

void ResearchArticleWriter::CreateArticle()
{
	researchArticle = new Article();
}

void ResearchArticleWriter::WriteTitle()
{
	auto a = researchArticle->text;
	researchArticle->text += std::string("Research article");
	researchArticle->text += std::string("\n\n");
}

void ResearchArticleWriter::WriteAnnotation()
{
	researchArticle->text += std::string("This is a research article");
	researchArticle->text += std::string("\n");
}

void ResearchArticleWriter::WriteBody()
{
	researchArticle->text += std::string("Lots of text about research");
	researchArticle->text += std::string("\n");
}

void ResearchArticleWriter::WriteReferences()
{
	researchArticle->text += std::string("Big list of another articles");
	researchArticle->text += std::string("\n");
}

Article* ResearchArticleWriter::GetResult()
{
	return researchArticle;
}

ResearchArticleWriter::~ResearchArticleWriter()
{
	if (researchArticle != nullptr)
		delete researchArticle;
}

ReviewArticleWriter::ReviewArticleWriter()
{
	reviewArticle = nullptr;
}

void ReviewArticleWriter::CreateArticle()
{
	reviewArticle = new Article();
}

void ReviewArticleWriter::WriteTitle()
{
	reviewArticle->text += std::string("Review article");
	reviewArticle->text += std::string("\n\n");
}

void ReviewArticleWriter::WriteAnnotation()
{
	reviewArticle->text += std::string("This is a review article");
	reviewArticle->text += std::string("\n");
}

void ReviewArticleWriter::WriteBody()
{
	reviewArticle->text += std::string("Some text about article theme");
	reviewArticle->text += std::string("\n");
}

void ReviewArticleWriter::WriteReferences()
{
	reviewArticle->text += std::string("List of another articles");
	reviewArticle->text += std::string("\n");
}

Article * ReviewArticleWriter::GetResult()
{
	return reviewArticle;
}

ReviewArticleWriter::~ReviewArticleWriter()
{
	if (reviewArticle != nullptr)
		delete reviewArticle;
}

Director::Director(ArticleWriter* inputWriter): writer(inputWriter)
{

}

void Director::Construct()
{
	writer->CreateArticle();//reset
	writer->WriteTitle();
	writer->WriteAnnotation();
	writer->WriteBody();
	writer->WriteReferences();
}

void Director::ChangeWriter(ArticleWriter * inputWriter)
{
	writer = inputWriter;
}

void RunBuilder()
{
	auto researchWriter = new ResearchArticleWriter();
	auto reviewWriter = new ReviewArticleWriter();

	auto director = new Director(researchWriter);
	director->Construct();
	auto article = researchWriter->GetResult();
	article->Print();

	std::cout << "\n";

	director->ChangeWriter(reviewWriter);
	director->Construct();
	director->Construct();
	article = reviewWriter->GetResult();
	article->Print();
}

