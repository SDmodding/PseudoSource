// File Line: 29
// RVA: 0x8B140
void __fastcall UFG::ReadGenericXMLList(
        SimpleXML::XMLDocument *xml_doc,
        UFG::qList<UFG::qString,UFG::qString,1,0> *output_list,
        const char *root_node_name,
        const char *child_node_name,
        const char *attribName,
        const char *attribVal)
{
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *i; // rsi
  SimpleXML::XMLNodeData *mData; // rax
  pugi::xml_node_struct *v12; // rax
  pugi::xml_node_struct *v13; // rax
  const char *value; // rbx
  char *v15; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rcx
  pugi::xml_attribute_struct *j; // r9
  const char *name; // r8
  pugi::xml_node_struct *root; // rax
  pugi::xml_node_struct *first_child; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rax
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax

  Node = SimpleXML::XMLDocument::GetNode(xml_doc, root_node_name, 0i64);
  for ( i = SimpleXML::XMLDocument::GetChildNode(xml_doc, child_node_name, Node);
        i;
        i = SimpleXML::XMLDocument::GetNode(xml_doc, child_node_name, i) )
  {
    mData = i->mData;
    if ( attribName )
    {
      if ( mData->mNode._root )
      {
        for ( j = mData->mNode._root->first_attribute; j; j = j->next_attribute )
        {
          name = j->name;
          if ( name && !strcmp(attribName, name) )
          {
            value = &customCaption;
            if ( j->value )
              value = j->value;
            if ( !value )
              break;
            if ( !attribVal )
            {
              v15 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
              if ( v15 )
                goto LABEL_32;
              v16 = 0i64;
              goto LABEL_34;
            }
            if ( UFG::qStringCompareInsensitive(value, attribVal, -1) )
              break;
            root = i->mData->mNode._root;
            if ( root && (first_child = root->first_child) != 0i64 )
            {
              value = &customCaption;
              if ( first_child->value )
                value = first_child->value;
            }
            else
            {
              value = &customCaption;
            }
            v15 = UFG::qMalloc(0x28ui64, "Generic XML List String Matching Attribute", 0i64);
            if ( !v15 )
            {
              v16 = 0i64;
              goto LABEL_34;
            }
            goto LABEL_32;
          }
        }
      }
    }
    else
    {
      v12 = mData->mNode._root;
      if ( v12 && (v13 = v12->first_child) != 0i64 )
      {
        value = &customCaption;
        if ( v13->value )
          value = v13->value;
      }
      else
      {
        value = &customCaption;
      }
      v15 = UFG::qMalloc(0x28ui64, "Generic XML List String", 0i64);
      if ( v15 )
      {
LABEL_32:
        UFG::qString::qString((UFG::qString *)v15, value);
        v16 = v21;
      }
      else
      {
        v16 = 0i64;
      }
LABEL_34:
      mPrev = output_list->mNode.mPrev;
      mPrev->mNext = v16;
      v16->mPrev = mPrev;
      v16->mNext = &output_list->mNode;
      output_list->mNode.mPrev = v16;
    }
  }
}

// File Line: 67
// RVA: 0x8B360
void __fastcall UFG::ReadGenericXMLList(
        const char *xml_filename,
        UFG::qList<UFG::qString,UFG::qString,1,0> *output_list,
        const char *root_node_name,
        const char *child_node_name,
        const char *attribName,
        const char *attribVal)
{
  SimpleXML::XMLDocument *v9; // r14

  v9 = SimpleXML::XMLDocument::Open(xml_filename, 1ui64, 0i64);
  UFG::ReadGenericXMLList(v9, output_list, root_node_name, child_node_name, attribName, attribVal);
  if ( v9 )
  {
    SimpleXML::XMLDocumentData::~XMLDocumentData(v9->mData);
    UFG::qMemoryPool::Free(v9->mPool, v9->mData);
    operator delete[](v9);
  }
}

