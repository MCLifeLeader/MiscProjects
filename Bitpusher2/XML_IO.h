/****************************************************************************
Program:    ged2sql2.exe
Author:     Mike Carey
Date:			July 1, 2002
Last Mod:	July 3, 2002
Compiler:   Microsoft .NET C++
Email:		mbcarey@trilument.com

****************************************************************************
Comments:

Note: 		
****************************************************************************/
//#pragma once

#ifndef __XML_IO_H
#define __XML_IO_H

// Basic XML Parsing Data Structure
struct XMLNODE {
   XMLNODE *xmlParent;      // All Chilren Know their Parents
   XMLNODE *xmlChild;       // Parents Only Know first Child
   XMLNODE *xmlSiblingNxt;  // Siblings Know only closest kin
   XMLNODE *xmlSiblingPrv;  // Siblings Know only closest kin
   
	bool bHasChild;
	bool bHasSibling;
   bool bDeletedNode;
   bool bFoundClosingTag;  // Did we find a closing tag?
   
   char *szElementName;    // Element Name
   char *szElementData;    // Element Data
   
   DWORD dwIndex;          // Position found in element Create Process.. This does not get reindexed.
};

// This is a quick index for all of the Nodes
struct XMLNODELIST {
   XMLNODE     *xmlNode;
   XMLNODELIST *xmlNodeListNxt;
};

// XML Reader Write class
class XMLReaderWriter
{
	public:
   XMLReaderWriter();         // default constructor
   ~XMLReaderWriter();        // default destructor
   
   bool XMLReadFile();        // Read an XML File to Memory
   bool XMLWriteFile();       // Write an XML File to Disk
   
   bool AddSibling( char *szElementName, char *szElementData );      // Add a sibling to current Node
   bool AddChild( char *szElementName, char *szElementData );        // Add a child to current Node
   
   bool ChangeNodeData( char *szElementName, char *szElementData );  // Change or Add Element Data to Current Node
   
   DWORD GetxmlError( void );	// get the error code
   
   bool SetNode( DWORD dwSetIndex );   // Set current Node Based on dwIndex 
   
   bool MoveToChild();        // Move to current Nodes Child
   bool MoveToParent();       // Move to current Nodes Parent
   bool MoveToSiblingNxt();   // Move to current Nodes Next Sibling
   bool MoveToSiblingPrv();   // Move to current Nodes Prev Sibling

   bool RemoveNode( DWORD dwIndex );        // Remove a node based on an index
   
   protected:
   
   private:

   // Creates the first Node... A call to AddChild or AddSibling will create this node
   bool CreateFirstNode( char *szElementName, char *szElementData );
   void CleanAllNodes();      // Remove all Elements from Memory
   
   public:
//   protected:
//   private:
   XMLNODELIST *hxmlNodeList; // xmlNodeList Quick index Linked List Head pointer for XMLNODE's
   XMLNODELIST *xmlNodeList;  // xmlNodeList current or Active xmlNodeList
   
   XMLNODE *xmlParentNode;    // The Root Parent Node
   XMLNODE *xmlNode;          // The current or active xmlNode

   DWORD dwNodesCreated;      // Total Nodes Created // This is also the Node Index
   DWORD dwNodesDeleted;      // Total Nodes Deleted
   
   DWORD dwErrorFlag;
};

// Returnable Error Codes that can be accumulativly returned through the | operator
#define XML_NO_ELEMENT_NAME 0x00000001
#define XML_NO_ELEMENT_DATA 0x00000002
#define XML_CHILD_PRESENT	 0X00000004
#define XML_SIBLING_PRESENT 0x00000008
#define XML_NODE_LIST_ERR   0x00000010
#define XML_ELMNT_FOUND     0x00000020
#define XML_ELMNT_NOT_FOUND 0x00000040
#define XML_BAD_INDEX_VAL   0x00000080
#define XML_PLACEHOLDER06   0x00000100
#define XML_PLACEHOLDER07   0x00000200
#define XML_PLACEHOLDER08   0x00000400
#define XML_PLACEHOLDER09   0x00000800
#define XML_PLACEHOLDER10   0x00001000
#define XML_PLACEHOLDER11   0x00002000
#define XML_PLACEHOLDER12   0x00004000
#define XML_PLACEHOLDER13   0x00008000
#define XML_PLACEHOLDER14   0x00010000
#define XML_NO_VALID_NODES  0x40000000
#define XML_INVALID_NODE    0x80000000

/*
int InitDLLCommunication( void );
int CloseDLLCommunications( void );
*/

#endif // #ifndef __XML_IO_H
