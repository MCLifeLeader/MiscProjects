// This is the main project file for VC++ application project 
// generated using an Application Wizard.

// This is the interface function calls to the DLL that will handle my XML Reading and Writing.
#include "stdafx.h"
#include "XML_IO.h"

//public:
XMLReaderWriter::XMLReaderWriter()
/****************************************************************************
	Purpose: default constructor

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
   hxmlNodeList   = NULL;  // xmlNode Quick index Linked List Head pointer
   xmlNodeList    = NULL;  // xmlNodeList current or Active xmlNodeList
   
   xmlParentNode  = NULL;  // The Root Parent Node
   xmlNode        = NULL;  // The current or active xmlNode 

   dwNodesCreated = NULL;  // Total Nodes Created // This is also the Node Index
   dwNodesDeleted = NULL;  // Total Nodes Deleted
   
   dwErrorFlag		= NULL;	// Set default value for dwErrorFlag
}

XMLReaderWriter::~XMLReaderWriter()
/****************************************************************************
	Purpose: default destructor

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
   CleanAllNodes();
}

bool XMLReaderWriter::XMLReadFile()
/****************************************************************************
	Purpose: Read an XML File to Memory

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	bool bNodeCreated = false;
	dwErrorFlag = NULL;

	return bNodeCreated;
}

bool XMLReaderWriter::XMLWriteFile()
/****************************************************************************
	Purpose: Write an XML File to Disk

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	bool bNodeCreated = false;
	dwErrorFlag = NULL;

	return bNodeCreated;
}

bool XMLReaderWriter::AddSibling( char *szElementName, char *szElementData )
/****************************************************************************
	Purpose: Add a sibling to current Node and then move to the Sibling Node
				If no parent create the parent node.
	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	bool bNodeCreated = false;
	dwErrorFlag = NULL;
	
	// Check to see if we have a good active node
	if( xmlNode )
	{
		// do we have an element name
		if( szElementName != NULL )
		{
			// do we have a child already attached to this node?
			if( xmlNode->bHasChild == false )
			{
				xmlNode->xmlSiblingNxt		= new XMLNODE;				// Make a new node
				xmlNode->bHasSibling			= true;						// We now have a child
				bNodeCreated					= true;						// We now have a new Node

				// if current node has a parent use that parent Else you are at the top node and means that there are no
				// parents only siblings so attach the first node ever created as parent node.
				if( xmlNode->xmlParent )
					xmlNode->xmlSiblingNxt->xmlParent = xmlNode->xmlParent;	// Set the Child's Parent Node...  Who's My Daddy?
				else
					xmlNode->xmlSiblingNxt->xmlParent = xmlParentNode;	// Set the Child's Parent Node...  Who's My Daddy?
				
				xmlNode = xmlNode->xmlSiblingNxt;						// Set the Active Node to the Child
				
				if( xmlNodeList )												// is our current node valid
				{
					xmlNodeList->xmlNodeListNxt = new XMLNODELIST;	// create a new index node list
					xmlNodeList = xmlNodeList->xmlNodeListNxt;		// Move to next element.

					xmlNodeList->xmlNode = xmlNode;						// add the xmlNode in the node list
					xmlNodeList->xmlNodeListNxt = NULL;					// Set testable NULL's
				}
				else
				{
					dwErrorFlag = XML_NODE_LIST_ERR;						// Set Flag
				}

				// NULL out unused data for now.
				xmlNode->xmlChild = xmlNode->xmlSiblingNxt = NULL;
				// set default flags to false
				xmlNode->bDeletedNode = xmlNode->bFoundClosingTag = xmlNode->bHasChild = xmlNode->bHasSibling = false;
				
				xmlNode->szElementName = new char [ strlen( szElementName ) + 1 ];
				strcpy( xmlNode->szElementName, szElementName );
				
				// Check to see if we have Element Data			
				if( szElementData )
				{
					xmlNode->szElementData = new char [ strlen( szElementData ) + 1 ];
					strcpy( xmlNode->szElementData, szElementData );
				}
				else
				{
					xmlNode->szElementData = NULL; // No element data found... set this to NULL

					// Carry the error Code down if it was the last executed.
					if( dwErrorFlag == XML_NODE_LIST_ERR )					
						dwErrorFlag = XML_NO_ELEMENT_DATA | XML_NODE_LIST_ERR; // Set Flag
					else
						dwErrorFlag = XML_NO_ELEMENT_DATA; // Set Flag
				}
			}
			else
			{
				dwErrorFlag = XML_CHILD_PRESENT; // Set Flag
			}
		}
		else
		{
			if( xmlNode->bHasChild == true )
			{
				dwErrorFlag = XML_NO_ELEMENT_NAME | XML_CHILD_PRESENT; // Set Flag
			}
			else
			{
				dwErrorFlag = XML_NO_ELEMENT_NAME; // Set Flag
			}
		}
		
		if( xmlParentNode )
		{
			xmlParentNode->dwIndex = dwNodesCreated;
			dwNodesCreated++;		
		}
	}
	else
	{
		// The current Node is invalid check to see if we have a default parent node
		if( xmlParentNode )
		{
			// if we have the default parent node set error code for current node
			// There was a problem in node creation
			dwErrorFlag = XML_INVALID_NODE;
		}
		else
		{
			// at this point we do not have a default xmlParentNode
			// this then creates the default parent node for the entire tree list
			bNodeCreated = CreateFirstNode( szElementName, szElementData );
		}
	}
	
   return bNodeCreated;
}

bool XMLReaderWriter::AddChild( char *szElementName, char *szElementData )
/****************************************************************************
	Purpose: Add a child to current Node and then move to the child Node
				If no parent create the parent node.
	Input:

   Output:

   Return:

   Parameters:

	Notes:	
****************************************************************************/
{
	bool bNodeCreated = false;
	dwErrorFlag = NULL;
	
	// Check to see if we have a good active node
	if( xmlNode )
	{
		// do we have an element name
		if( szElementName != NULL )
		{
			// do we have a child already attached to this node?
			if( xmlNode->bHasChild == false )
			{
				xmlNode->xmlChild		= new XMLNODE;				// Make a new node
				xmlNode->bHasChild	= true;						// We now have a child
				bNodeCreated			= true;						// We now have a new Node

				xmlNode->xmlChild->xmlParent = xmlNode;	// Set the Child's Parent Node...  Who's My Daddy?				
				xmlNode = xmlNode->xmlChild;					// Set the Active Node to the Child
				
				if( xmlNodeList )												// is our current node valid
				{
					xmlNodeList->xmlNodeListNxt = new XMLNODELIST;	// create a new index node list
					xmlNodeList = xmlNodeList->xmlNodeListNxt;		// Move to next element.

					xmlNodeList->xmlNode = xmlNode;						// add the xmlNode in the node list
					xmlNodeList->xmlNodeListNxt = NULL;					// Set testable NULL's
				}
				else
				{
					dwErrorFlag = XML_NODE_LIST_ERR;
				}

				// NULL out unused data for now.
				xmlNode->xmlChild = xmlNode->xmlSiblingNxt = xmlNode->xmlSiblingPrv = NULL;
				
				// set default flags to false
				xmlNode->bDeletedNode = xmlNode->bFoundClosingTag = xmlNode->bHasChild = xmlNode->bHasSibling = false;
				
				// create some string memory
				xmlNode->szElementName = new char [ strlen( szElementName ) + 1 ];
				strcpy( xmlNode->szElementName, szElementName );
				
				// Check to see if we have Element Data			
				if( szElementData )
				{
					// create some string memory
					xmlNode->szElementData = new char [ strlen( szElementData ) + 1 ];
					strcpy( xmlNode->szElementData, szElementData );
				}
				else
				{
					xmlNode->szElementData = NULL; // No element data found... set this to NULL
					
					// Carry the error Code down if it there was an error
					if( dwErrorFlag == XML_NODE_LIST_ERR )					
						dwErrorFlag = XML_NO_ELEMENT_DATA | XML_NODE_LIST_ERR; // Set Flag
					else
						dwErrorFlag = XML_NO_ELEMENT_DATA; // Set Flag
				}
			}
			else
			{
				dwErrorFlag = XML_CHILD_PRESENT; // Set Flag
			}
		}
		else
		{
			if( xmlNode->bHasChild == true )
			{
				dwErrorFlag = XML_NO_ELEMENT_NAME | XML_CHILD_PRESENT; // Set Flag
			}
			else
			{
				dwErrorFlag = XML_NO_ELEMENT_NAME; // Set Flag
			}
		}
		
		if( xmlParentNode )
		{
			// Set Node Index
			xmlParentNode->dwIndex = dwNodesCreated;
			dwNodesCreated++;		
		}
	}
	else
	{
		// The current Node is invalid check to see if we have a default parent node
		if( xmlParentNode )
		{
			// if we have the default parent node set error code for current node
			// There was a problem in node creation
			dwErrorFlag = XML_INVALID_NODE;
		}
		else
		{
			// at this point we do not have a default xmlParentNode
			// this then creates the default parent node for the entire tree list
			bNodeCreated = CreateFirstNode( szElementName, szElementData );
		}
	}
	
   return bNodeCreated;
}

bool XMLReaderWriter::ChangeNodeData( char *szElementName, char *szElementData )
/****************************************************************************
	Purpose: Change or Add Element Data to Current Node   

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
   bool bNodeChanged = false;
   dwErrorFlag = NULL;
   
   // Check to see if we are on a good xmlNode structure
   if( xmlNode )
   {
		// Check to see if we have a new ElementName
		if( szElementName )
		{
			// Delete the old name
			if( xmlNode->szElementName )
				delete [] xmlNode->szElementName;
			
			// allocate a little memory for the new name
			xmlNode->szElementName = new char [ strlen( szElementName ) + 1 ];
			
			// copy the new name
			strcpy( xmlNode->szElementName, szElementName );
			
			bNodeChanged = true;
		}
		
		// Check to see if we have new ElementData
		if( szElementData )
		{
			// delete the old Data
			if( xmlNode->szElementData )
				delete [] xmlNode->szElementData;
			
			// allocate a little memory for th new data
			xmlNode->szElementData = new char [ strlen( szElementData ) + 1 ];
			
			// copy the new data
			strcpy( xmlNode->szElementData, szElementData );
			
			bNodeChanged = true;
		}
   }
   else
   {
		// Set error code
		dwErrorFlag = XML_INVALID_NODE;
   }
   
   return bNodeChanged;
}

DWORD XMLReaderWriter::GetxmlError( void )
/****************************************************************************
	Purpose: Get the last error code value and return it to the user

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	return( dwErrorFlag );
}

bool XMLReaderWriter::SetNode( DWORD dwSetIndex )
/****************************************************************************
	Purpose: Set current Node Based on dwIndex

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	bool bNodeFound = false;
	dwErrorFlag = XML_ELMNT_NOT_FOUND;	// set flag
	
	// do we even have an xmlParentNode
	if( xmlParentNode )
	{
		// do we have a valid Value to Search By
		if( dwNodesCreated >= dwSetIndex )
		{
			// start the search at the top of the index list
			xmlNodeList = hxmlNodeList;
			while( xmlNodeList )
			{
				// Find the xmlNode with the correct index value
				if( xmlNodeList->xmlNode->dwIndex == dwSetIndex )
				{
					// Verify that the node has not been marked as deleted
					// if the node has been marked as deleted it will not be returned as a valid value
					if( xmlNodeList->xmlNode->bDeletedNode == false )
					{
						// set the current active xmlNode to the value given from the index.
						xmlNode = xmlNodeList->xmlNode;
						dwErrorFlag = XML_ELMNT_FOUND; // set flag
						bNodeFound = true;
						break;
					}
				}
				// move to the next element
				xmlNodeList = xmlNodeList->xmlNodeListNxt;
			}			
		}
		else
		{
			dwErrorFlag = XML_BAD_INDEX_VAL;	// set flag
		}
	}
	else
	{
		dwErrorFlag = XML_NO_VALID_NODES;	// set flag
	}

	return bNodeFound;
}

bool XMLReaderWriter::MoveToChild()
/****************************************************************************
	Purpose: Move to current Nodes Child

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	bool bNodeFound = false;
	dwErrorFlag = NULL;
	
	// do we have a good xmlNode Element
	if( xmlNode )
	{
		// does that element have a child element
		if( xmlNode->xmlChild )
		{
			// move the current node to the child element
			xmlNode = xmlNode->xmlChild;
			dwErrorFlag = XML_ELMNT_FOUND;	// set flag
			bNodeFound = true;
		}
		else
		{
			dwErrorFlag = XML_ELMNT_NOT_FOUND;	// set flag
		}
	}
	else
	{
		dwErrorFlag = XML_INVALID_NODE;	// set flag
	}
	
	return bNodeFound;
}

bool XMLReaderWriter::MoveToParent()
/****************************************************************************
	Purpose: Move to current Nodes Parent

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	bool bNodeFound = false;
	dwErrorFlag = NULL;

	// do we have a good xmlNode Element
	if( xmlNode )
	{
		// does that element have a sibling element
		if( xmlNode->xmlParent )
		{
			// move the current node to the sibling element
			xmlNode = xmlNode->xmlParent;
			dwErrorFlag = XML_ELMNT_FOUND;	// set flag
			bNodeFound = true;
		}
		else
		{
			dwErrorFlag = XML_ELMNT_NOT_FOUND;	// set flag
		}
	}
	else
	{
		dwErrorFlag = XML_INVALID_NODE;	// set flag
	}

	return bNodeFound;
}

bool XMLReaderWriter::MoveToSiblingNxt()
/****************************************************************************
	Purpose: Move to current Nodes Next Sibling

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	bool bNodeFound = false;
	dwErrorFlag = NULL;

	// do we have a good xmlNode Element
	if( xmlNode )
	{
		// does that element have a sibling element
		if( xmlNode->xmlSiblingNxt )
		{
			// move the current node to the sibling element
			xmlNode = xmlNode->xmlSiblingNxt;
			dwErrorFlag = XML_ELMNT_FOUND;	// set flag
			bNodeFound = true;
		}
		else
		{
			dwErrorFlag = XML_ELMNT_NOT_FOUND;	// set flag
		}
	}
	else
	{
		dwErrorFlag = XML_INVALID_NODE;	// set flag
	}

	return bNodeFound;
}

bool XMLReaderWriter::MoveToSiblingPrv()
/****************************************************************************
	Purpose: Move to current Nodes Prev Sibling

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	bool bNodeFound = false;
	dwErrorFlag = NULL;

	// do we have a good xmlNode Element
	if( xmlNode )
	{
		// does that element have a sibling element
		if( xmlNode->xmlSiblingPrv )
		{
			// move the current node to the sibling element
			xmlNode = xmlNode->xmlSiblingPrv;
			dwErrorFlag = XML_ELMNT_FOUND;	// set flag
			bNodeFound = true;
		}
		else
		{
			dwErrorFlag = XML_ELMNT_NOT_FOUND;	// set flag
		}
	}
	else
	{
		dwErrorFlag = XML_INVALID_NODE;	// set flag
	}

	return bNodeFound;
}

bool XMLReaderWriter::RemoveNode( DWORD dwIndex )
/****************************************************************************
	Purpose: Remove current Nodes Child

	Input: DWORD dwIndex

   Output:

   Return:

   Parameters:

	Notes: You can pass in an index value or Zero for the current node your on.
			 If it is set to Zero it will mark the current node for deletion.
			 Invalid values will return an error code.
			 xmlParentNode is a reserved node and must be manually set as current node
			 if it is to be marked as deleted.
****************************************************************************/
{
	bool bNodeFound = false;
	dwErrorFlag = XML_ELMNT_NOT_FOUND;	// set flag
	
	// do we have a good active node
	if( xmlNode )
	{
		// protect the parent node
		if( dwIndex > 0 )
		{		
			// do we have a valid Value to Search By
			if( dwNodesCreated >= dwIndex )
			{
				// start the search at the top of the index list
				xmlNodeList = hxmlNodeList;
				while( xmlNodeList )
				{
					// Find the xmlNode with the correct index value
					if( xmlNodeList->xmlNode->dwIndex == dwIndex )
					{
						// Verify that the node has not been marked as deleted
						// if the node has been marked as deleted it will not be returned as a valid value
						if( xmlNodeList->xmlNode->bDeletedNode == false )
						{
							// set the current active xmlNode to the value given from the index.
							xmlNode = xmlNodeList->xmlNode;
							dwErrorFlag = XML_ELMNT_FOUND; // set flag
							xmlNode->bDeletedNode = true;
							bNodeFound = true;
							break;
						}
					}
					// move to the next element
					xmlNodeList = xmlNodeList->xmlNodeListNxt;					
				}			
			}
			else
			{
				dwErrorFlag = XML_BAD_INDEX_VAL;	// set flag
			}
		}
		else
		{
			xmlNode->bDeletedNode = true;	// mark the node as deleted.
			dwErrorFlag = XML_ELMNT_FOUND; // set flag
			bNodeFound = true;
		}
	}
	else
	{
		dwErrorFlag = XML_NO_VALID_NODES;	// set flag
	}

	return bNodeFound;
}
//   protected:

//   private:

bool XMLReaderWriter::CreateFirstNode( char *szElementName, char *szElementData )   
/****************************************************************************
	Purpose: Creates the first Node

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
	bool bNodeCreated = false;
	dwErrorFlag = NULL;
	
	// do we have an element name or data to write
	if( ( ( szElementName != NULL ) || ( szElementData != NULL ) ) && ( hxmlNodeList == NULL ) && ( xmlParentNode == NULL ) )
	{
		xmlParentNode = new XMLNODE;	// main XML Node
		xmlNode = xmlParentNode;

		hxmlNodeList = new XMLNODELIST;	// XML Node List Index
		xmlNodeList = hxmlNodeList;
		
		hxmlNodeList->xmlNode = xmlParentNode;		// set the first element in the node list
		hxmlNodeList->xmlNodeListNxt = NULL;
		
		// This Grandfather node does not have anything right now so set everything to NULL
		xmlParentNode->xmlChild = xmlParentNode->xmlParent				= NULL;
		xmlParentNode->xmlSiblingNxt = xmlParentNode->xmlSiblingPrv = NULL;
		xmlParentNode->bDeletedNode = xmlParentNode->bDeletedNode	= false;
		xmlParentNode->bHasChild = xmlParentNode->bHasSibling					= false;
		
		// Check to See if we have an Element Name
		// No data will be stored if we do not have an element Name
		if( szElementName )
		{
			bNodeCreated = true;	// We have an Element Name
			
			xmlParentNode->szElementName = new char [ strlen( szElementName ) + 1 ];
			strcpy( xmlParentNode->szElementName, szElementName );
			
			// Check to see if we have Element Data			
			if( szElementData )
			{
				xmlParentNode->szElementData = new char [ strlen( szElementData ) + 1 ];
				strcpy( xmlParentNode->szElementData, szElementData );
			}
		}
		else
		{
			dwErrorFlag = XML_NO_ELEMENT_NAME; // Set Flag
		}
	}
	
	if( xmlParentNode )
	{
		// Node index count
		xmlParentNode->dwIndex = dwNodesCreated;
		dwNodesCreated++;		
	}
	
   return bNodeCreated;
}

void XMLReaderWriter::CleanAllNodes()
/****************************************************************************
	Purpose: Remove all Elements from Memory

	Input:

   Output:

   Return:

   Parameters:

	Notes:
****************************************************************************/
{
   XMLNODELIST *Tmp, *Curr;
	Tmp = Curr = hxmlNodeList;
   
   // if there is an xmlNodeList then there are xmlNodes or at least should be
   // if not we will not be cleaning up after out selves. Oh dear... lost memory.
	if( hxmlNodeList )
	{
	   // continue looping until all nodes are found
		while( Curr )
		{
			Tmp	= Curr;                 // set Tmp to the current element to work with
			Curr	= Curr->xmlNodeListNxt; // move current element to the next element
			
			if( Tmp->xmlNode )            // if we have an xmlNode then we can do some clean up
         {
            if( Tmp->xmlNode->szElementData )	// check for szElementData
            {
               delete [] Tmp->xmlNode->szElementData; // delete the element data string
               Tmp->xmlNode->szElementData = NULL;
            }
            
            if( Tmp->xmlNode->szElementName )	// check for element name
            {
               delete [] Tmp->xmlNode->szElementName; // delete the element name string
               Tmp->xmlNode->szElementName = NULL;
            }
            
            Tmp->xmlNode->bDeletedNode = true;        // set the deleted node flag to true
            
            delete Tmp->xmlNode;                      // delete the xmlNode
            
            Tmp->xmlNode = NULL;                      // set it to NULL to protect use of bad memory
         }
         
			delete Tmp; // delete the active xmlNodeList element

			Tmp = NULL; // set it to NULL to protect against bad memory use
		}
	}
}

/*
// This code is for use in establishing communications to a DLL
// This is how you define your pointer to a function
__declspec( dllimport ) int XML_DLL_Test_Message( char *szString );
typedef int ( * XMLMESSAGE )( char *szString );

HINSTANCE hDLL;            // Handle to DLL
XMLMESSAGE XMLDLLMessage;    // Function pointer	

int InitDLLCommunication( void )
{
	int uReturnVal;
	
#ifdef _DEBUG
	hDLL = LoadLibrary("D:\\CODE\\XMLParseRW\\Debug\\XMLParseRW.dll");
#else
	hDLL = LoadLibrary("D:\\CODE\\XMLParseRW\\Release\\XMLParseRW.dll");
#endif

	if ( hDLL != NULL )
	{
		// This is where to initilize all of the function calls into the DLL by function pointer
		XMLDLLMessage = ( XMLMESSAGE )GetProcAddress( hDLL, "XML_DLL_Test_Message" );
		if ( !XMLDLLMessage )
		{
			// handle the error
			FreeLibrary( hDLL );
			return 1;
		}
		else
		{
			// This is a test but is how you would call the function using the new function pointer
			uReturnVal = XMLDLLMessage( "Test String" );
		}
	}
	
	return 1;
}

int CloseDLLCommunications( void )
{
	return ( FreeLibrary( hDLL ) );
}

*/
