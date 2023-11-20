// File Line: 16
// RVA: 0x13021A0
void __fastcall hkTrackerTypeTreeNode::hkTrackerTypeTreeNode(hkTrackerTypeTreeNode *this, hkTrackerTypeTreeNode::Type type)
{
  this->m_type = type;
  this->m_name.m_start = 0i64;
  this->m_name.m_end = 0i64;
  this->m_dimension = 0;
  this->m_contains = 0i64;
  this->m_next = 0i64;
}

// File Line: 24
// RVA: 0x1301E10
hkBool *__fastcall hkTrackerTypeTreeNode::isNamedType(hkTrackerTypeTreeNode *this, hkBool *result)
{
  hkBool *v2; // rax

  if ( (unsigned int)(this->m_type - 16) <= 2 || this->m_type == 3 )
  {
    result->m_bool = 1;
    v2 = result;
  }
  else
  {
    result->m_bool = 0;
    v2 = result;
  }
  return v2;
}

// File Line: 29
// RVA: 0x1301E40
hkBool *__fastcall hkTrackerTypeTreeNode::isNamedType(hkTrackerTypeTreeNode *this, hkBool *result, const char *name)
{
  hkBool *v3; // rbx
  const char *v4; // rsi
  hkTrackerTypeTreeNode *v5; // rdi
  hkBool *v6; // rax
  hkBool resulta; // [rsp+38h] [rbp+10h]
  hkBool v8; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = name;
  v5 = this;
  if ( hkTrackerTypeTreeNode::isNamedType(this, &resulta)->m_bool
    && hkSubString::operator==(&v5->m_name, &v8, v4)->m_bool )
  {
    v3->m_bool = 1;
    v6 = v3;
  }
  else
  {
    v3->m_bool = 0;
    v6 = v3;
  }
  return v6;
}

// File Line: 34
// RVA: 0x1301EB0
void __fastcall hkTrackerTypeTreeNode::dumpType(hkTrackerTypeTreeNode *this, hkOstream *stream)
{
  hkOstream *v2; // rbx
  hkTrackerTypeTreeNode *v3; // rsi
  hkTrackerTypeTreeNode *i; // rdi
  hkOstream *v5; // rax
  hkOstream *v6; // rax

  v2 = stream;
  v3 = this;
  switch ( this->m_type )
  {
    case 0:
      hkOstream::operator<<(stream, "(Unknown)");
      break;
    case 1:
      hkTrackerTypeTreeNode::dumpType(this->m_contains, stream);
      hkOstream::operator<<(v2, pattern);
      break;
    case 2:
      hkTrackerTypeTreeNode::dumpType(this->m_contains, stream);
      hkOstream::operator<<(v2, "&");
      break;
    case 3:
      operator<<(stream, &this->m_name);
      hkOstream::operator<<(v2, 60);
      for ( i = v3->m_contains; i; i = i->m_next )
      {
        if ( i != v3->m_contains )
          hkOstream::operator<<(v2, 44);
        hkTrackerTypeTreeNode::dumpType(i, v2);
      }
      hkOstream::operator<<(v2, 62);
      break;
    case 4:
      hkOstream::operator<<(stream, "int8");
      break;
    case 5:
      hkOstream::operator<<(stream, "int16");
      break;
    case 6:
      hkOstream::operator<<(stream, "int32");
      break;
    case 7:
      hkOstream::operator<<(stream, "int64");
      break;
    case 8:
      hkOstream::operator<<(stream, "uint8");
      break;
    case 9:
      hkOstream::operator<<(stream, "uint16");
      break;
    case 0xA:
      hkOstream::operator<<(stream, "uint32");
      break;
    case 0xB:
      hkOstream::operator<<(stream, "uint64");
      break;
    case 0xC:
      hkOstream::operator<<(stream, "float32");
      break;
    case 0xD:
      hkOstream::operator<<(stream, "float64");
      break;
    case 0xE:
      hkOstream::operator<<(stream, "bool");
      break;
    case 0xF:
      hkOstream::operator<<(stream, "void");
      break;
    case 0x10:
    case 0x11:
    case 0x12:
      operator<<(stream, &this->m_name);
      break;
    case 0x13:
      hkTrackerTypeTreeNode::dumpType(this->m_contains, stream);
      v5 = hkOstream::operator<<(v2, "[");
      v6 = hkOstream::operator<<(v5, v3->m_dimension, (int)v5);
      hkOstream::operator<<(v6, "]");
      break;
    case 0x14:
      hkOstream::operator<<(stream, this->m_dimension, this->m_type);
      break;
    default:
      return;
  }
}

// File Line: 157
// RVA: 0x13021D0
void __fastcall hkTrackerTypeTreeNode::dumpType(hkTrackerTypeTreeNode *node, hkOstream *stream)
{
  if ( node )
    hkTrackerTypeTreeNode::dumpType(node, stream);
  else
    hkOstream::operator<<(stream, "(Unknown)");
}

