// File Line: 17
// RVA: 0xEC37FC
char __fastcall OSuite::FSerialize(OSuite::ZUtf8Buffer *buffer, OSuite::ZMetric *pMetric, OSuite::ZMetricProperties *props)
{
  OSuite::ZUtf8Buffer *v3; // r14
  OSuite::ZMetricProperties *v4; // rbx
  OSuite::ZMetric *v5; // r15
  char v6; // si
  OSuite::ZJsonDocument *v7; // rdi
  OSuite::ZJsonDocument *v8; // rax
  OSuite::ZJsonDocument *v9; // rax
  OSuite::ZJsonValue *v10; // rax
  OSuite::ZJsonValue *v11; // rbx
  OSuite::ZJsonValue *v12; // rax
  OSuite::ZJsonValue *v13; // rbx
  OSuite::ZString *v14; // rax
  OSuite::ZJsonValue *v15; // rax
  OSuite::ZJsonValue *v16; // rbx
  OSuite::ZString *v17; // rax
  OSuite::ZJsonValue *v18; // rax
  OSuite::ZJsonValue *v19; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase **v20; // rax
  OSuite::ZJsonDocument *v21; // rax
  OSuite::ZJsonDocument *v22; // rax
  OSuite::ZJsonDocument *v23; // rbx
  OSuite::ZJsonValue *v24; // rax
  OSuite::ZJsonValue *v25; // rdi
  OSuite::ZString *v26; // rax
  OSuite::ZJsonValue *v27; // rax
  OSuite::ZJsonValue *v28; // rdi
  OSuite::ZJsonValue *v29; // rax
  OSuite::ZJsonValue *v30; // rdi
  char v31; // al
  OSuite::ZJsonValue *v32; // rax
  OSuite::ZString sValue; // [rsp+20h] [rbp-E0h]
  OSuite::ZDateTime v35; // [rsp+38h] [rbp-C8h]
  __int64 v36; // [rsp+50h] [rbp-B0h]
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZMetric::IStoredData *,OSuite::ZString> v37; // [rsp+60h] [rbp-A0h]
  OSuite::ZMetricProperties::ZTransferIterator result; // [rsp+D0h] [rbp-30h]

  v3 = buffer;
  v4 = props;
  v5 = pMetric;
  v6 = 0;
  LODWORD(v35.vfptr) = 0;
  OSuite::ZDateTime::ZDateTime(&v35);
  _mm_store_si128((__m128i *)&result.m_it.m_iterator.m_iterator.m_pList, (__m128i)0i64);
  _mm_store_si128((__m128i *)&result.m_it.m_iterator.m_iterator.m_parents.m_pList, (__m128i)0i64);
  v7 = 0i64;
  result.m_it.m_pMap = 0i64;
  OSuite::ZMetricProperties::TransferIterator(v4, &result);
  if ( !OSuite::ZMetricProperties::ZTransferIterator::AtEnd(&result) )
  {
    v8 = (OSuite::ZJsonDocument *)OSuite::ZObject::operator new(0x30ui64);
    if ( v8 )
    {
      v8->m_Pairs.m_pLists = 0i64;
      OSuite::ZJsonDocument::ZJsonDocument(v8);
      v7 = v9;
    }
    v10 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
    v11 = v10;
    if ( v10 )
    {
      v10->m_literal.m_pString = 0i64;
      v10->m_array.m_pList = 0i64;
      v10->m_object = 0i64;
      OSuite::ZString::ZString(&sValue, "Metadata");
      v6 = 1;
      OSuite::ZJsonValue::ZJsonValue(v11, &sValue, 1);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    OSuite::ZString::ZString((OSuite::ZString *)&v35.m_nYear, "s__Name");
    OSuite::ZJsonObject::Add((OSuite::ZJsonObject *)&v7->vfptr, (OSuite::ZString *)&v35.m_nYear, v13);
    OSuite::ZString::~ZString((OSuite::ZString *)&v35.m_nYear);
    if ( v6 & 1 )
      OSuite::ZString::~ZString(&sValue);
  }
  while ( !OSuite::ZMetricProperties::ZTransferIterator::AtEnd(&result) )
  {
    v14 = (OSuite::ZString *)OSuite::ZMetricProperties::ZTransferIterator::Value(&result);
    if ( OSuite::ZString::operator bool(v14) )
    {
      v15 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
      v16 = v15;
      if ( v15 )
      {
        v15->m_literal.m_pString = 0i64;
        v15->m_array.m_pList = 0i64;
        v15->m_object = 0i64;
        v17 = (OSuite::ZString *)OSuite::ZMetricProperties::ZTransferIterator::Value(&result);
        OSuite::ZJsonValue::ZJsonValue(v16, v17, 1);
        v19 = v18;
      }
      else
      {
        v19 = 0i64;
      }
      v20 = OSuite::ZMetricProperties::ZTransferIterator::Key(&result);
      OSuite::ZJsonObject::Add((OSuite::ZJsonObject *)&v7->vfptr, (OSuite::ZString *)v20, v19);
    }
    OSuite::ZMetricProperties::ZTransferIterator::Next(&result);
  }
  if ( v7 )
  {
    OSuite::ZJsonSerializer::Serialize((OSuite::ZJsonSerializer *)&v35, v3, v7);
    v7->vfptr->__vecDelDtor((OSuite::ZObject *)&v7->vfptr, 1u);
    OSuite::ZUtf8Buffer::Append(v3, ",");
  }
  v21 = (OSuite::ZJsonDocument *)OSuite::ZObject::operator new(0x30ui64);
  if ( v21 )
  {
    v21->m_Pairs.m_pLists = 0i64;
    OSuite::ZJsonDocument::ZJsonDocument(v21);
    v23 = v22;
  }
  else
  {
    v23 = 0i64;
  }
  v24 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
  v25 = v24;
  if ( v24 )
  {
    v24->m_literal.m_pString = 0i64;
    v24->m_array.m_pList = 0i64;
    v24->m_object = 0i64;
    v26 = (OSuite::ZString *)OSuite::ZHttpConnection::Url((OSuite::ZHttpConnection *)v5);
    OSuite::ZJsonValue::ZJsonValue(v25, v26, 1);
    v28 = v27;
  }
  else
  {
    v28 = 0i64;
  }
  OSuite::ZString::ZString(&sValue, "s__Name");
  OSuite::ZJsonObject::Add((OSuite::ZJsonObject *)&v23->vfptr, &sValue, v28);
  OSuite::ZString::~ZString(&sValue);
  v37.m_iterator.m_iterator.m_pList = 0i64;
  v37.m_iterator.m_iterator.m_pElement = 0i64;
  v37.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::ZMetric::Iterator(v5, &v37);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v37.m_iterator.m_iterator) )
  {
    v36 = 0i64;
    (*((void (__fastcall **)(OSuite::ZObjectVtbl *, int *))v37.m_iterator.m_iterator.m_pElement[2].vfptr->__vecDelDtor
     + 1))(
      v37.m_iterator.m_iterator.m_pElement[2].vfptr,
      &v35.m_nYear);
    v29 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
    v30 = v29;
    if ( v29 )
    {
      v29->m_literal.m_pString = 0i64;
      v29->m_array.m_pList = 0i64;
      v29->m_object = 0i64;
      v31 = (*((__int64 (**)(void))v37.m_iterator.m_iterator.m_pElement[2].vfptr->__vecDelDtor + 3))();
      OSuite::ZJsonValue::ZJsonValue(v30, (OSuite::ZString *)&v35.m_nYear, v31);
    }
    else
    {
      v32 = 0i64;
    }
    OSuite::ZJsonObject::Add(
      (OSuite::ZJsonObject *)&v23->vfptr,
      (OSuite::ZString *)&v37.m_iterator.m_iterator.m_pElement[1].m_pLeft,
      v32);
    OSuite::ZString::~ZString((OSuite::ZString *)&v35.m_nYear);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v37.m_iterator.m_iterator.vfptr);
  }
  v37.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
  v37.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  v37.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  v37.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v37.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v37.m_iterator.m_iterator.m_parents.m_pList )
    v37.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)v37.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZJsonSerializer::Serialize((OSuite::ZJsonSerializer *)&v35, v3, v23);
  if ( v23 )
    v23->vfptr->__vecDelDtor((OSuite::ZObject *)&v23->vfptr, 1u);
  OSuite::ZMetricProperties::ZTransferIterator::~ZTransferIterator(&result);
  OSuite::ZJsonSerializer::~ZJsonSerializer(&v35);
  return 1;
}

// File Line: 67
// RVA: 0xEC35A4
char __fastcall OSuite::FSerialize(OSuite::ZMemoryBufferChain *bufferChain, OSuite::ZMetric *pMetric, OSuite::ZMetricProperties *props, unsigned __int64 nMemoryThreshold, bool *end)
{
  OSuite::ZMemoryBuffer *v5; // rdi
  signed __int64 v6; // rbx
  OSuite::ZMetricProperties *v7; // rbp
  OSuite::ZMetric *v8; // rsi
  OSuite::ZMemoryBufferChain *v9; // r13
  OSuite::ZMemoryBuffer *v10; // rax
  OSuite::ZMemoryBuffer *v11; // rax
  char result; // al
  bool v13; // r14
  OSuite::ZMemoryBuffer *v14; // rax
  OSuite::ZMemoryBuffer *v15; // rax
  OSuite::ZMemoryBuffer *v16; // rbp
  OSuite::ZMemoryBuffer *v17; // rax
  float v18; // xmm6_4
  bool v19; // r12
  __int64 v20; // rbx
  unsigned __int64 v21; // rax
  float v22; // xmm1_4
  signed int v23; // ebx
  unsigned __int64 v24; // rax
  const char *v25; // rdx
  unsigned __int64 v26; // rbx
  const void *v27; // rax
  unsigned __int64 v28; // rbx
  OSuite::ZStringBuilder v29; // [rsp+20h] [rbp-88h]

  v5 = 0i64;
  v6 = nMemoryThreshold;
  v7 = props;
  v8 = pMetric;
  v9 = bufferChain;
  if ( pMetric )
  {
    v29.m_Chars.m_pList = 0i64;
    OSuite::ZStringBuilder::ZStringBuilder(&v29, 0x400ui64);
    v13 = OSuite::FSerialize((OSuite::ZUtf8Buffer *)&v29, v8, v7);
    if ( !v13 )
      goto LABEL_29;
    v14 = (OSuite::ZMemoryBuffer *)OSuite::ZObject::operator new(0x38ui64);
    if ( v14 )
    {
      v14->m_pNext = 0i64;
      v14->m_pBuffer = 0i64;
      v14->m_pIndex = 0i64;
      OSuite::ZMemoryBuffer::ZMemoryBuffer(v14);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    v17 = OSuite::ZHttpStreamReader::Size(v9);
    *end = 0;
    v18 = (float)(signed int)v6;
    v19 = v17 == 0i64;
    if ( v6 < 0 )
      v18 = v18 + 1.8446744e19;
    v20 = ((__int64 (*)(void))v9->vfptr->Size)();
    v21 = OSuite::ZStringBuilder::Count(&v29);
    v22 = (float)((signed int)v21 + v20);
    if ( (signed __int64)(v21 + v20) < 0 )
      v22 = v22 + 1.8446744e19;
    if ( (float)(v22 + (float)(v18 * 0.1)) >= v18 )
      *end = 1;
    if ( v19 || (v23 = 1, *end) )
      v23 = 2;
    v24 = OSuite::ZStringBuilder::Count(&v29);
    OSuite::ZMemoryBuffer::Allocate(v16, v24 + v23, 0i64, 0i64);
    v13 = 0;
    v25 = "[";
    if ( !v19 )
      v25 = ",";
    if ( OSuite::ZMemoryBuffer::Write(v16, v25, 1ui64) != 1
      || (v26 = OSuite::ZStringBuilder::Count(&v29),
          v27 = OSuite::ZUtf8Buffer::Buffer((OSuite::ZUtf8Buffer *)&v29),
          v28 = OSuite::ZMemoryBuffer::Write(v16, v27, v26),
          v28 != OSuite::ZStringBuilder::Count(&v29))
      || (OSuite::ZMemoryBufferChain::Chain(v9, v16), *end) && OSuite::ZMemoryBuffer::Write(v16, "]", 1ui64) != 1 )
    {
LABEL_29:
      ((void (*)(void))v9->vfptr->Flush)();
    }
    else
    {
      v13 = 1;
    }
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v29);
    result = v13;
  }
  else
  {
    v10 = (OSuite::ZMemoryBuffer *)OSuite::ZObject::operator new(0x38ui64);
    if ( v10 )
    {
      v10->m_pNext = 0i64;
      v10->m_pBuffer = 0i64;
      v10->m_pIndex = 0i64;
      OSuite::ZMemoryBuffer::ZMemoryBuffer(v10);
      v5 = v11;
    }
    OSuite::ZMemoryBuffer::Allocate(v5, 1ui64, "]", 1ui64);
    OSuite::ZMemoryBufferChain::Chain(v9, v5);
    *end = 1;
    result = 1;
  }
  return result;
}

