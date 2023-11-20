// File Line: 14
// RVA: 0x4ADF10
bool __fastcall UFG::ProgressionTracker::LoadDependencyGraph(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rbp
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // r14
  char v4; // r15
  SimpleXML::XMLNode *v5; // rax
  SimpleXML::XMLNode *v6; // rbx
  char *v7; // rax
  SimpleXML::XMLNode *v8; // rdi
  char *v9; // rbx
  char *v10; // rsi
  UFG::GameSlice *v11; // rbx
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]
  UFG::qSymbol v14; // [rsp+58h] [rbp+10h]

  v1 = this;
  v2 = SimpleXML::XMLDocument::Open(this->mDependencyGraphName.mData, 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    v4 = 0;
    v5 = SimpleXML::XMLDocument::GetNode(v2, "dependencygraph", 0i64);
    v6 = v5;
    if ( v5 )
    {
      v7 = SimpleXML::XMLNode::GetAttribute(v5, "globalalternatelayer");
      if ( v7 )
        UFG::qString::Set(&v1->mGlobalAlternateLayer, v7);
      v8 = SimpleXML::XMLDocument::GetChildNode(v3, "graphitem", v6);
      if ( v8 )
      {
        while ( 1 )
        {
          v9 = SimpleXML::XMLNode::GetAttribute(v8, "name");
          v10 = SimpleXML::XMLNode::GetAttribute(v8, "requires");
          UFG::qSymbol::create_from_string(&result, v9);
          if ( !result.mUID )
            break;
          v11 = (UFG::GameSlice *)UFG::qBaseTreeRB::Get(&v1->mDisabledGameSlices.mTree, result.mUID);
          if ( !v11 )
          {
            if ( !result.mUID )
              break;
            v11 = (UFG::GameSlice *)UFG::qBaseTreeRB::Get(&v1->mGameSlices.mTree, result.mUID);
            if ( !v11 )
            {
              if ( !result.mUID )
                break;
              v11 = (UFG::GameSlice *)UFG::qBaseTreeRB::Get(&v1->mContainerGameSlices.mTree, result.mUID);
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
              if ( (signed int)v11->mChildren.mCount > 0 )
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
          v8 = SimpleXML::XMLDocument::GetNode(v3, "graphitem", v8);
          if ( !v8 )
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

