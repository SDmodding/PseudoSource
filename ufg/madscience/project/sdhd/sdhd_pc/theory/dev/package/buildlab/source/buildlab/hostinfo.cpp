// File Line: 21
// RVA: 0x1465860
__int64 dynamic_initializer_for__UFG::HostInfo::mHostDomainName__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostDomainName);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HostInfo::mHostDomainName__);
}

// File Line: 22
// RVA: 0x1465840
__int64 dynamic_initializer_for__UFG::HostInfo::mHostComputerName__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostComputerName);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HostInfo::mHostComputerName__);
}

// File Line: 23
// RVA: 0x1465880
__int64 dynamic_initializer_for__UFG::HostInfo::mHostIP__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostIP);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HostInfo::mHostIP__);
}

// File Line: 24
// RVA: 0x14658C0
__int64 dynamic_initializer_for__UFG::HostInfo::mHostUserName__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostUserName);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HostInfo::mHostUserName__);
}

// File Line: 25
// RVA: 0x14658A0
__int64 dynamic_initializer_for__UFG::HostInfo::mHostLoginName__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostLoginName);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HostInfo::mHostLoginName__);
}

// File Line: 29
// RVA: 0x1510E0
char __fastcall UFG::HostInfo::Load(const char *filename)
{
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // rbp
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *ChildNode; // rsi
  char *Name; // rdi
  char *Value; // rbx
  UFG::qString *v8; // rcx

  v2 = SimpleXML::XMLDocument::Open(filename, 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    Node = SimpleXML::XMLDocument::GetNode(v2, "HostInfo", 0i64);
    if ( Node )
    {
      ChildNode = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, Node);
      if ( ChildNode )
      {
        while ( 1 )
        {
          Name = SimpleXML::XMLNode::GetName(ChildNode);
          Value = SimpleXML::XMLNode::GetValue(ChildNode);
          if ( !(unsigned int)UFG::qStringCompare("DomainName", Name, -1) )
            break;
          if ( !(unsigned int)UFG::qStringCompare("ComputerName", Name, -1) )
          {
            v8 = &UFG::HostInfo::mHostComputerName;
            goto LABEL_14;
          }
          if ( !(unsigned int)UFG::qStringCompare("IP", Name, -1) )
          {
            v8 = &UFG::HostInfo::mHostIP;
            goto LABEL_14;
          }
          if ( !(unsigned int)UFG::qStringCompare("UserName", Name, -1) )
          {
            v8 = &UFG::HostInfo::mHostUserName;
            goto LABEL_14;
          }
          if ( !(unsigned int)UFG::qStringCompare("LoginName", Name, -1) )
          {
            v8 = &UFG::HostInfo::mHostLoginName;
            goto LABEL_14;
          }
LABEL_15:
          ChildNode = SimpleXML::XMLDocument::GetNode(v3, 0i64, ChildNode);
          if ( !ChildNode )
            goto LABEL_16;
        }
        v8 = &UFG::HostInfo::mHostDomainName;
LABEL_14:
        UFG::qString::Set(v8, Value);
        goto LABEL_15;
      }
LABEL_16:
      SimpleXML::XMLDocument::~XMLDocument(v3);
      operator delete[](v3);
      return 1;
    }
    else
    {
      UFG::qPrintf("ERROR: Could not find root node %s in filename %s\n", "HostInfo", filename);
      return 0;
    }
  }
  else
  {
    UFG::qPrintf("ERROR: Could not open filename %s\n", filename);
    return 0;
  }
}

