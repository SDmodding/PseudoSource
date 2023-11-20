// File Line: 22
// RVA: 0xE5CCD0
hkResult *__fastcall hkSerializeDeprecated::saveXmlPackfile(hkSerializeDeprecated *this, hkResult *result, const void *object, hkClass *klass, hkStreamWriter *writer, hkPackfileWriter::Options *options, hkPackfileWriter::AddObjectListener *userListener, hkSerializeUtil::ErrorDetails *errorOut)
{
  hkResult *v8; // rbx
  hkResult *v9; // rax

  v8 = result;
  if ( !errorOut || errorOut->id.m_storage )
  {
    result->m_enum = 1;
    v9 = result;
  }
  else
  {
    errorOut->id.m_storage = 7;
    hkStringPtr::operator=(
      &errorOut->defaultMessage,
      "XML packfile support is not linked. Perhaps you have HK_EXCLUDE_FEATURE_SerializeDeprecatedPre700 in hkProductFeatures");
    v8->m_enum = 1;
    v9 = v8;
  }
  return v9;
}

// File Line: 31
// RVA: 0xE5CD30
__int64 __fastcall hkSerializeDeprecated::isLoadable(hkSerializeDeprecated *this, hkSerializeUtil::FormatDetails *details)
{
  return 0i64;
}

// File Line: 36
// RVA: 0xE5CD40
hkResource *__fastcall hkSerializeDeprecated::loadOldPackfile(hkSerializeDeprecated *this, hkStreamReader *sr, hkSerializeUtil::FormatDetails *details, hkSerializeUtil::ErrorDetails *errorOut)
{
  if ( errorOut && !errorOut->id.m_storage )
  {
    errorOut->id.m_storage = 7;
    hkStringPtr::operator=(
      &errorOut->defaultMessage,
      "Packfile versioning support is not linked. Versioning packfiles at runtime was deprecated in Havok-7.0.0.\n"
      "To do so requires linking some deprecated code from Source/Common/Compat/Deprecated\n"
      "If you are using hkProductFeatures.cxx, ensure you do not define HK_EXCLUDE_FEATURE_SerializeDeprecatedPre700.\n"
      "Note that by default this pulls in a lot of code and data (mainly previous versions of hkClasses).\n"
      "Some extra effort is required to strip the unused code and data but it will still cost several hundred Kb.\n"
      "Alternatively, you can use Tools/PackfileConvert/AsseetCc2 to convert your packfiles the the latest version before loading.\n");
  }
  return 0i64;
}

// File Line: 45
// RVA: 0xE5CD80
hkObjectResource *__fastcall hkSerializeDeprecated::loadOldPackfileOnHeap(hkSerializeDeprecated *this, hkStreamReader *sr, hkSerializeUtil::FormatDetails *details, hkSerializeUtil::ErrorDetails *errorOut)
{
  if ( errorOut && !errorOut->id.m_storage )
  {
    errorOut->id.m_storage = 7;
    hkStringPtr::operator=(
      &errorOut->defaultMessage,
      "Packfile versioning support is not linked. Versioning packfiles at runtime was deprecated in Havok-7.0.0.\n"
      "To do so requires linking some deprecated code from Source/Common/Compat/Deprecated\n"
      "If you are using hkProductFeatures.cxx, ensure you do not define HK_EXCLUDE_FEATURE_SerializeDeprecatedPre700.\n"
      "Note that by default this pulls in a lot of code and data (mainly previous versions of hkClasses).\n"
      "Some extra effort is required to strip the unused code and data but it will still cost several hundred Kb.\n"
      "Alternatively, you can use Tools/PackfileConvert/AsseetCc2 to convert your packfiles the the latest version before loading.\n");
  }
  return 0i64;
}

// File Line: 54
// RVA: 0xE5CDC0
hkResult *__fastcall hkSerializeDeprecated::readXmlPackfileHeader(hkSerializeDeprecated *this, hkResult *result, hkStreamReader *stream, hkSerializeDeprecated::XmlPackfileHeader *out, hkSerializeUtil::ErrorDetails *errorOut)
{
  hkSerializeUtil::ErrorDetails *v5; // rdi
  hkStreamReader *v6; // rbp
  hkResult *v7; // rbx
  hkXmlParser::Node *v8; // rsi
  hkXmlParser::Node *v9; // rcx
  hkResult *v10; // rax
  hkXmlParser v11; // [rsp+20h] [rbp-38h]
  hkXmlParser::Node *ret; // [rsp+68h] [rbp+10h]

  v5 = errorOut;
  v6 = stream;
  v7 = result;
  if ( errorOut )
  {
    hkXmlParser::hkXmlParser(&v11);
    v8 = 0i64;
    ret = 0i64;
    if ( hkXmlParser::nextNode(&v11, (hkResult *)&errorOut, &ret, v6)->m_enum == HK_SUCCESS )
    {
      v9 = ret;
      if ( ret->type == 1 )
        v8 = ret;
      if ( v8 && (_QWORD)v8[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 )
      {
        if ( !(unsigned int)hkString::strCmp((const char *)((_QWORD)v8[1].vfptr & 0xFFFFFFFFFFFFFFFEui64), "hkpackfile")
          && !v5->id.m_storage )
        {
          v5->id.m_storage = 7;
          hkStringPtr::operator=(
            &v5->defaultMessage,
            "Packfile versioning support is not linked. Versioning packfiles at runtime was deprecated in Havok-7.0.0.\n"
            "To do so requires linking some deprecated code from Source/Common/Compat/Deprecated\n"
            "If you are using hkProductFeatures.cxx, ensure you do not define HK_EXCLUDE_FEATURE_SerializeDeprecatedPre70"
            "0.\n"
            "Note that by default this pulls in a lot of code and data (mainly previous versions of hkClasses).\n"
            "Some extra effort is required to strip the unused code and data but it will still cost several hundred Kb.\n"
            "Alternatively, you can use Tools/PackfileConvert/AsseetCc2 to convert your packfiles the the latest version "
            "before loading.\n");
        }
        v9 = ret;
      }
      hkReferencedObject::removeReference((hkReferencedObject *)&v9->vfptr);
    }
    hkXmlParser::~hkXmlParser(&v11);
    v7->m_enum = 1;
    v10 = v7;
  }
  else
  {
    v10 = result;
    result->m_enum = 1;
  }
  return v10;
}

// File Line: 77
// RVA: 0xE5CCC0
bool __fastcall hkSerializeDeprecated::isEnabled(hkSerializeDeprecated *this)
{
  return 0;
}

// File Line: 82
// RVA: 0xE5CEC0
hkSerializeDeprecated *__fastcall createInstance()
{
  if ( !(_S1_44 & 1) )
  {
    *(_DWORD *)&s_instance.m_memSizeAndFlags = 0x1FFFF;
    _S1_44 |= 1u;
    s_instance.vfptr = (hkBaseObjectVtbl *)&hkSerializeDeprecated::`vftable';
    atexit(createInstance_::_2_::_dynamic_atexit_destructor_for__s_instance__);
  }
  hkReferencedObject::addReference((hkReferencedObject *)&s_instance.vfptr);
  return &s_instance;
}

// File Line: 88
// RVA: 0x15D8A10
hkSingletonInitNode *dynamic_initializer_for__hkSingletonRegisterhkSerializeDeprecated__()
{
  hkSingletonInitNode *result; // rax

  hkSingletonRegisterhkSerializeDeprecated.m_next = hkSingletonInitList;
  result = &hkSingletonRegisterhkSerializeDeprecated;
  hkSingletonInitList = &hkSingletonRegisterhkSerializeDeprecated;
  return result;
}

