// File Line: 14
// RVA: 0x4ADF10
bool __fastcall UFG::ProgressionTracker::LoadDependencyGraph(UFG::ProgressionTracker *this)
{
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // r14
  char v4; // r15
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *v6; // rbx
  char *Attribute; // rax
  SimpleXML::XMLNode *ChildNode; // rdi
  char *v9; // rbx
  char *v10; // rsi
  UFG::GameSlice *v11; // rbx
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol v14; // [rsp+58h] [rbp+10h] BYREF

  v2 = SimpleXML::XMLDocument::Open(this->mDependencyGraphName.mData, 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    v4 = 0;
    Node = SimpleXML::XMLDocument::GetNode(v2, "dependencygraph", 0i64);
    v6 = Node;
    if ( Node )
    {
      Attribute = SimpleXML::XMLNode::GetAttribute(Node, "globalalternatelayer");
      if ( Attribute )
        UFG::qString::Set(&this->mGlobalAlternateLayer, Attribute);
      ChildNode = SimpleXML::XMLDocument::GetChildNode(v3, "graphitem", v6);
      if ( ChildNode )
      {
        while ( 1 )
        {
          v9 = SimpleXML::XMLNode::GetAttribute(ChildNode, "name");
          v10 = SimpleXML::XMLNode::GetAttribute(ChildNode, "requires");
          UFG::qSymbol::create_from_string(&result, v9);
          if ( !result.mUID )
            break;
          v11 = (UFG::GameSlice *)UFG::qBaseTreeRB::Get(&this->mDisabledGameSlices.mTree, result.mUID);
          if ( !v11 )
          {
            if ( !result.mUID )
              break;
            v11 = (UFG::GameSlice *)UFG::qBaseTreeRB::Get(&this->mGameSlices.mTree, result.mUID);
            if ( !v11 )
            {
              if ( !result.mUID )
                break;
              v11 = (UFG::GameSlice *)UFG::qBaseTreeRB::Get(&this->mContainerGameSlices.mTree, result.mUID);
            }
          }
LABEL_13:
          if ( v10 )
          {
            if ( !strcmp(v10, "DISABLED") )
              v4 = 1;
            UFG::qSymbol::create_from_string(&v14, v10);
            if ( v11 )
            {
              if ( (int)v11->mChildren.mCount > 0 )
                v11 = *v11->mChildren.mppArray;
              if ( v11 )
              {
                UFG::GameSlice::AddDependency(v11, v10);
                v11->mMinimumDependentsRequired = v11->mDependents.mCount;
              }
            }
          }
          else
          {
            v11->mRoot = 1;
          }
          ChildNode = SimpleXML::XMLDocument::GetNode(v3, "graphitem", ChildNode);
          if ( !ChildNode )
            goto LABEL_23;
        }
        v11 = 0i64;
        goto LABEL_13;
      }
    }
LABEL_23:
    SimpleXML::XMLDocument::~XMLDocument(v3);
    operator delete[](v3);
    LOBYTE(v2) = v4 == 0;
  }
  return (char)v2;
}

