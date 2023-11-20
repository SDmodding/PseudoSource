// File Line: 21
// RVA: 0x1465860
__int64 dynamic_initializer_for__UFG::HostInfo::mHostDomainName__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostDomainName);
  return atexit(dynamic_atexit_destructor_for__UFG::HostInfo::mHostDomainName__);
}

// File Line: 22
// RVA: 0x1465840
__int64 dynamic_initializer_for__UFG::HostInfo::mHostComputerName__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostComputerName);
  return atexit(dynamic_atexit_destructor_for__UFG::HostInfo::mHostComputerName__);
}

// File Line: 23
// RVA: 0x1465880
__int64 dynamic_initializer_for__UFG::HostInfo::mHostIP__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostIP);
  return atexit(dynamic_atexit_destructor_for__UFG::HostInfo::mHostIP__);
}

// File Line: 24
// RVA: 0x14658C0
__int64 dynamic_initializer_for__UFG::HostInfo::mHostUserName__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostUserName);
  return atexit(dynamic_atexit_destructor_for__UFG::HostInfo::mHostUserName__);
}

// File Line: 25
// RVA: 0x14658A0
__int64 dynamic_initializer_for__UFG::HostInfo::mHostLoginName__()
{
  UFG::qString::qString(&UFG::HostInfo::mHostLoginName);
  return atexit(dynamic_atexit_destructor_for__UFG::HostInfo::mHostLoginName__);
}

// File Line: 29
// RVA: 0x1510E0
char __fastcall UFG::HostInfo::Load(const char *filename)
{
  const char *v1; // rbx
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // rbp
  SimpleXML::XMLNode *v4; // rax
  SimpleXML::XMLNode *v5; // rsi
  char *v6; // rdi
  const char *v7; // rbx
  UFG::qString *v8; // rcx
  char result; // al

  v1 = filename;
  v2 = SimpleXML::XMLDocument::Open(filename, 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    v4 = SimpleXML::XMLDocument::GetNode(v2, "HostInfo", 0i64);
    if ( v4 )
    {
      v5 = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, v4);
      if ( v5 )
      {
        while ( 1 )
        {
          v6 = SimpleXML::XMLNode::GetName(v5);
          v7 = SimpleXML::XMLNode::GetValue(v5);
          if ( !(unsigned int)UFG::qStringCompare("DomainName", v6, -1) )
            break;
          if ( !(unsigned int)UFG::qStringCompare("ComputerName", v6, -1) )
          {
            v8 = &UFG::HostInfo::mHostComputerName;
            goto LABEL_14;
          }
          if ( !(unsigned int)UFG::qStringCompare("IP", v6, -1) )
          {
            v8 = &UFG::HostInfo::mHostIP;
            goto LABEL_14;
          }
          if ( !(unsigned int)UFG::qStringCompare("UserName", v6, -1) )
          {
            v8 = &UFG::HostInfo::mHostUserName;
            goto LABEL_14;
          }
          if ( !(unsigned int)UFG::qStringCompare("LoginName", v6, -1) )
          {
            v8 = &UFG::HostInfo::mHostLoginName;
            goto LABEL_14;
          }
LABEL_15:
          v5 = SimpleXML::XMLDocument::GetNode(v3, 0i64, v5);
          if ( !v5 )
            goto LABEL_16;
        }
        v8 = &UFG::HostInfo::mHostDomainName;
LABEL_14:
        UFG::qString::Set(v8, v7);
        goto LABEL_15;
      }
LABEL_16:
      SimpleXML::XMLDocument::~XMLDocument(v3);
      operator delete[](v3);
      result = 1;
    }
    else
    {
      UFG::qPrintf("ERROR: Could not find root node '%s' in filename '%s'\n", "HostInfo", v1);
      result = 0;
    }
  }
  else
  {
    UFG::qPrintf("ERROR: Could not open filename '%s'\n", v1);
    result = 0;
  }
  return result;
}

