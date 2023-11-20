// File Line: 29
// RVA: 0x8B140
void __fastcall UFG::ReadGenericXMLList(SimpleXML::XMLDocument *xml_doc, UFG::qList<UFG::qString,UFG::qString,1,0> *output_list, const char *root_node_name, const char *child_node_name, const char *attribName, const char *attribVal)
{
  const char *v6; // r12
  UFG::qList<UFG::qString,UFG::qString,1,0> *v7; // rdi
  SimpleXML::XMLDocument *v8; // r15
  SimpleXML::XMLNode *v9; // rax
  SimpleXML::XMLNode *i; // rsi
  SimpleXML::XMLNodeData *v11; // rax
  pugi::xml_node_struct *v12; // rax
  pugi::xml_node_struct *v13; // rax
  const char *v14; // rbx
  char *v15; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  pugi::xml_attribute_struct *j; // r9
  char *v19; // r8
  const char *v20; // rax
  __int64 v21; // r8
  int v22; // ecx
  int v23; // edx
  const char *v24; // rbx
  char *v25; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  pugi::xml_node_struct *v27; // rax
  pugi::xml_node_struct *v28; // rax
  const char *v29; // rbx
  char *v30; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v31; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rax

  v6 = child_node_name;
  v7 = output_list;
  v8 = xml_doc;
  v9 = SimpleXML::XMLDocument::GetNode(xml_doc, root_node_name, 0i64);
  for ( i = SimpleXML::XMLDocument::GetChildNode(v8, v6, v9); i; i = SimpleXML::XMLDocument::GetNode(v8, v6, i) )
  {
    v11 = i->mData;
    if ( attribName )
    {
      if ( v11->mNode._root )
      {
        for ( j = v11->mNode._root->first_attribute; j; j = j->next_attribute )
        {
          v19 = j->name;
          if ( v19 )
          {
            v20 = attribName;
            v21 = v19 - attribName;
            do
            {
              v22 = (unsigned __int8)v20[v21];
              v23 = *(unsigned __int8 *)v20 - v22;
              if ( *(unsigned __int8 *)v20 != v22 )
                break;
              ++v20;
            }
            while ( v22 );
            if ( !v23 )
            {
              v24 = &customWorldMapCaption;
              if ( j->value )
                v24 = j->value;
              if ( !v24 )
                break;
              if ( attribVal )
              {
                if ( UFG::qStringCompareInsensitive(v24, attribVal, -1) )
                  break;
                v27 = i->mData->mNode._root;
                if ( v27 && (v28 = v27->first_child) != 0i64 )
                {
                  v29 = &customWorldMapCaption;
                  if ( v28->value )
                    v29 = v28->value;
                }
                else
                {
                  v29 = &customWorldMapCaption;
                }
                v30 = UFG::qMalloc(0x28ui64, "Generic XML List String Matching Attribute", 0i64);
                if ( v30 )
                {
                  UFG::qString::qString((UFG::qString *)v30, v29);
                  v17 = v31;
                }
                else
                {
                  v17 = 0i64;
                }
              }
              else
              {
                v25 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
                if ( v25 )
                {
                  UFG::qString::qString((UFG::qString *)v25, v24);
                  v17 = v26;
                }
                else
                {
                  v17 = 0i64;
                }
              }
              goto LABEL_40;
            }
          }
        }
      }
    }
    else
    {
      v12 = v11->mNode._root;
      if ( v12 && (v13 = v12->first_child) != 0i64 )
      {
        v14 = &customWorldMapCaption;
        if ( v13->value )
          v14 = v13->value;
      }
      else
      {
        v14 = &customWorldMapCaption;
      }
      v15 = UFG::qMalloc(0x28ui64, "Generic XML List String", 0i64);
      if ( v15 )
      {
        UFG::qString::qString((UFG::qString *)v15, v14);
        v17 = v16;
      }
      else
      {
        v17 = 0i64;
      }
LABEL_40:
      v32 = v7->mNode.mPrev;
      v32->mNext = v17;
      v17->mPrev = v32;
      v17->mNext = &v7->mNode;
      v7->mNode.mPrev = v17;
    }
  }
}

// File Line: 67
// RVA: 0x8B360
void __fastcall UFG::ReadGenericXMLList(const char *xml_filename, UFG::qList<UFG::qString,UFG::qString,1,0> *output_list, const char *root_node_name, const char *child_node_name, const char *attribName, const char *attribVal)
{
  const char *v6; // rdi
  UFG::qList<UFG::qString,UFG::qString,1,0> *v7; // rsi
  const char *v8; // rbx
  SimpleXML::XMLDocument *v9; // r14

  v6 = root_node_name;
  v7 = output_list;
  v8 = child_node_name;
  v9 = SimpleXML::XMLDocument::Open(xml_filename, 1ui64, 0i64);
  UFG::ReadGenericXMLList(v9, v7, v6, v8, attribName, attribVal);
  if ( v9 )
  {
    SimpleXML::XMLDocumentData::~XMLDocumentData(v9->mData);
    UFG::qMemoryPool::Free(v9->mPool, v9->mData);
    operator delete[](v9);
  }
}

