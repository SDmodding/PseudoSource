// File Line: 16
// RVA: 0x13021A0
void __fastcall hkTrackerTypeTreeNode::hkTrackerTypeTreeNode(
        hkTrackerTypeTreeNode *this,
        hkTrackerTypeTreeNode::Type type)
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
  if ( (unsigned int)(this->m_type - 16) <= 2 || this->m_type == TYPE_REAL )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 29
// RVA: 0x1301E40
hkBool *__fastcall hkTrackerTypeTreeNode::isNamedType(hkTrackerTypeTreeNode *this, hkBool *result, const char *name)
{
  hkBool resulta; // [rsp+38h] [rbp+10h] BYREF
  hkBool v8; // [rsp+48h] [rbp+20h] BYREF

  if ( hkTrackerTypeTreeNode::isNamedType(this, &resulta)->m_bool
    && hkSubString::operator==(&this->m_name, &v8, name)->m_bool )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 34
// RVA: 0x1301EB0
void __fastcall hkTrackerTypeTreeNode::dumpType(hkTrackerTypeTreeNode *this, hkOstream *stream)
{
  hkTrackerTypeTreeNode *i; // rdi
  hkOstream *v5; // rax
  hkOstream *v6; // rax

  switch ( this->m_type )
  {
    case TYPE_VOID:
      hkOstream::operator<<(stream, "(Unknown)");
      break;
    case TYPE_BYTE:
      hkTrackerTypeTreeNode::dumpType(this->m_contains, stream);
      hkOstream::operator<<(stream, pattern);
      break;
    case TYPE_INT:
      hkTrackerTypeTreeNode::dumpType(this->m_contains, stream);
      hkOstream::operator<<(stream, "&");
      break;
    case TYPE_REAL:
      operator<<(stream, &this->m_name);
      hkOstream::operator<<(stream, 60);
      for ( i = this->m_contains; i; i = i->m_next )
      {
        if ( i != this->m_contains )
          hkOstream::operator<<(stream, 44);
        hkTrackerTypeTreeNode::dumpType(i, stream);
      }
      hkOstream::operator<<(stream, 62);
      break;
    case TYPE_VEC_4:
      hkOstream::operator<<(stream, "int8");
      break;
    case TYPE_VEC_8:
      hkOstream::operator<<(stream, "int16");
      break;
    case TYPE_VEC_12:
      hkOstream::operator<<(stream, "int32");
      break;
    case TYPE_VEC_16:
      hkOstream::operator<<(stream, "int64");
      break;
    case TYPE_OBJECT:
      hkOstream::operator<<(stream, "uint8");
      break;
    case TYPE_STRUCT:
      hkOstream::operator<<(stream, "uint16");
      break;
    case TYPE_CSTRING:
      hkOstream::operator<<(stream, "uint32");
      break;
    case TYPE_NUM_BASIC_TYPES:
      hkOstream::operator<<(stream, "uint64");
      break;
    case TYPE_OBJECT|TYPE_VEC_4:
      hkOstream::operator<<(stream, "float32");
      break;
    case TYPE_STRUCT|TYPE_VEC_4:
      hkOstream::operator<<(stream, "float64");
      break;
    case TYPE_CSTRING|TYPE_VEC_4:
      hkOstream::operator<<(stream, "bool");
      break;
    case TYPE_MASK_BASIC_TYPES:
      hkOstream::operator<<(stream, "void");
      break;
    case TYPE_ARRAY:
    case TYPE_ARRAY_BYTE:
    case TYPE_ARRAY_INT:
      operator<<(stream, &this->m_name);
      break;
    case TYPE_ARRAY_REAL:
      hkTrackerTypeTreeNode::dumpType(this->m_contains, stream);
      v5 = hkOstream::operator<<(stream, "[");
      v6 = hkOstream::operator<<(v5, this->m_dimension);
      hkOstream::operator<<(v6, "]");
      break;
    case TYPE_ARRAY_VEC_4:
      hkOstream::operator<<(stream, this->m_dimension);
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

