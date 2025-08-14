// #include <iostream>
// #include <fstream>
// #include <DuckX.h>
// #include "tinyxml2.h"

// using namespace std;
// using namespace tinyxml2;

// void parseXML(const char *filename)
// {
//     XMLDocument doc;
//     doc.LoadFile(filename);

//     XMLElement *root = doc.RootElement();
//     XMLElement *error;
//     XMLElement *attribute;

//     // Create a new Word document
//     Document *document = new Document();
//     document->Create();

//     for (error = root->FirstChildElement("Error"); error; error = error->NextSiblingElement("Error"))
//     {
//         int index = atoi(error->Attribute("index"));

//         Paragraph *paragraph = document->AddParagraph();
//         paragraph->AddText("Error Index: " + to_string(index));

//         for (attribute = error->FirstChildElement("Attribute"); attribute; attribute = attribute->NextSiblingElement("Attribute"))
//         {
//             string name = attribute->Attribute("name");
//             string value = attribute->Attribute("value");

//             paragraph = document->AddParagraph();
//             paragraph->AddText(name + ": " + value);
//         }
//     }

//     // Save the document
//     document->Save("output.docx");
//     document->Close();
//     delete document;

//     cout << "Content has been imported into output.docx" << endl;
// }

// int main()
// {
//     parseXML("errors.xml");
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <DuckX.h>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

void parseXML(const char *filename)
{
    XMLDocument doc;
    doc.LoadFile(filename);

    XMLElement *root = doc.RootElement();
    XMLElement *error;
    XMLElement *attribute;

    // Create a new Word document
    Document *document = new Document();
    document->Create();

    for (error = root->FirstChildElement("Error"); error; error = error->NextSiblingElement("Error"))
    {
        int index = atoi(error->Attribute("index"));

        Paragraph *paragraph = document->AddParagraph();
        paragraph->AddText("Error Index: " + to_string(index));

        string errorCode, errorDescription, errorSolution;

        for (attribute = error->FirstChildElement("Attribute"); attribute; attribute = attribute->NextSiblingElement("Attribute"))
        {
            string name = attribute->Attribute("name");
            string value = attribute->Attribute("value");

            if (name == "error_code")
            {
                errorCode = value;
            }
            else if (name == "error_description")
            {
                errorDescription = value;
            }
            else if (name == "error_solution")
            {
                errorSolution = value;
            }
        }

        paragraph = document->AddParagraph();
        paragraph->AddText("Error Code: " + errorCode);
        paragraph = document->AddParagraph();
        paragraph->AddText("Error Description: " + errorDescription);
        paragraph = document->AddParagraph();
        paragraph->AddText("Error Solution: " + errorSolution);
    }

    // Save the document
    document->Save("output.docx");
    document->Close();
    delete document;

    cout << "Content has been imported into output.docx" << endl;
}

int main()
{
    parseXML("errors.xml");
    return 0;
}