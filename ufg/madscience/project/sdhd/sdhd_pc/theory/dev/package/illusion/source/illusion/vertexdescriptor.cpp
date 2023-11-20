// File Line: 67
// RVA: 0x8D2C0
void __fastcall Illusion::VertexStreamElement::VertexStreamElement(Illusion::VertexStreamElement *this, Illusion::VertexStreamElementUsage _usage, Illusion::VertexSteamElementType _type, __int16 _stream, int _offset, UFG::qVector4 *default_value)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4

  this->usage = _usage;
  this->type = _type;
  this->stream = _stream;
  this->offset = _offset;
  switch ( _type )
  {
    case 0u:
      this->size = 12;
      break;
    case 1u:
      this->size = 16;
      break;
    case 2u:
    case 3u:
    case 4u:
    case 5u:
    case 6u:
    case 9u:
    case 0xEu:
    case 0xFu:
    case 0x10u:
      this->size = 4;
      break;
    case 7u:
    case 0xAu:
    case 0xBu:
    case 0xCu:
    case 0xDu:
      this->size = 8;
      break;
    case 8u:
      this->size = 6;
      break;
    default:
      this->size = 0;
      break;
  }
  if ( default_value )
  {
    v6 = default_value->y;
    v7 = default_value->z;
    v8 = default_value->w;
    this->mDefault.x = default_value->x;
    this->mDefault.y = v6;
    this->mDefault.z = v7;
    this->mDefault.w = v8;
    return;
  }
  if ( (signed int)_usage > 0 )
  {
    if ( (signed int)_usage <= 2 )
    {
      this->mDefault.z = 1.0;
      this->mDefault.w = 1.0;
      *(_QWORD *)&this->mDefault.x = 0i64;
      return;
    }
    if ( (signed int)_usage <= 4 )
    {
      this->mDefault.x = 1.0;
      this->mDefault.y = 1.0;
      this->mDefault.z = 1.0;
      this->mDefault.w = 1.0;
      return;
    }
  }
  *(_QWORD *)&this->mDefault.z = 0i64;
  *(_QWORD *)&this->mDefault.x = 0i64;
}

// File Line: 160
// RVA: 0x92730
UFG::qList<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor,1,0> *__fastcall Illusion::VertexStreamDescriptor::GetStreamDescriptors()
{
  if ( !(_S1_14 & 1) )
  {
    _S1_14 |= 1u;
    sVertexStreamDescriptors.mNode.mPrev = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)&sVertexStreamDescriptors;
    sVertexStreamDescriptors.mNode.mNext = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)&sVertexStreamDescriptors;
    atexit(Illusion::VertexStreamDescriptor::GetStreamDescriptors_::_2_::_dynamic_atexit_destructor_for__sVertexStreamDescriptors__);
  }
  Illusion::gVertexStreamDescriptors = &sVertexStreamDescriptors;
  return &sVertexStreamDescriptors;
}

// File Line: 184
// RVA: 0x8D1C0
void __fastcall Illusion::VertexStreamDescriptor::VertexStreamDescriptor(Illusion::VertexStreamDescriptor *this, const char *name, unsigned int name_uid)
{
  Illusion::VertexStreamDescriptor *v3; // rdi
  UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *v4; // rbx
  UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *v5; // rax

  v3 = this;
  v4 = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Illusion::VertexStreamDescriptor::`vftable';
  this->mName = name;
  this->mNameUID = name_uid;
  *(_QWORD *)&this->mTotalElements = 0i64;
  this->mStreamRuntimeFlags = 0;
  this->mIndexStreamMultiplier = 1;
  this->mIndexStreamAsVertexStream = 0;
  UFG::qMemSet(this->mElements, 0, 0x240u);
  UFG::qMemSet(v3->mStreamNumElements, 0, 0x10u);
  UFG::qMemSet(v3->mStreamSizes, 0, 0x10u);
  if ( !(_S1_14 & 1) )
  {
    _S1_14 |= 1u;
    sVertexStreamDescriptors.mNode.mPrev = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)&sVertexStreamDescriptors;
    sVertexStreamDescriptors.mNode.mNext = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)&sVertexStreamDescriptors;
    atexit(Illusion::VertexStreamDescriptor::GetStreamDescriptors_::_2_::_dynamic_atexit_destructor_for__sVertexStreamDescriptors__);
  }
  Illusion::gVertexStreamDescriptors = &sVertexStreamDescriptors;
  v5 = sVertexStreamDescriptors.mNode.mPrev;
  sVertexStreamDescriptors.mNode.mPrev->mNext = v4;
  v4->mPrev = v5;
  v4->mNext = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)&sVertexStreamDescriptors;
  sVertexStreamDescriptors.mNode.mPrev = v4;
}

// File Line: 204
// RVA: 0x8DA20
void __fastcall Illusion::VertexStreamDescriptor::~VertexStreamDescriptor(Illusion::VertexStreamDescriptor *this)
{
  Illusion::VertexStreamDescriptor *v1; // rbx
  Illusion::VertexStreamDescriptorVtbl *v2; // rcx
  UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *v3; // rax
  Illusion::VertexStreamDescriptorVtbl *v4; // rcx
  UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *v5; // rax

  v1 = this;
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Illusion::VertexStreamDescriptor::`vftable';
  Illusion::VertexStreamDescriptor::GetStreamDescriptors();
  v1 = (Illusion::VertexStreamDescriptor *)((char *)v1 + 8);
  v2 = v1->vfptr;
  v3 = v1->mPrev;
  v2[1].ApplyUserRemapping = (void (__fastcall *)(Illusion::VertexStreamDescriptor *, UFG::qVector4 *))v3;
  v3->mPrev = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)v2;
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)v1;
  v1->mPrev = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)v1;
  v4 = v1->vfptr;
  v5 = v1->mPrev;
  v4[1].ApplyUserRemapping = (void (__fastcall *)(Illusion::VertexStreamDescriptor *, UFG::qVector4 *))v5;
  v5->mPrev = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)v4;
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)v1;
  v1->mPrev = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)v1;
}

// File Line: 221
// RVA: 0x8E0A0
void __fastcall Illusion::VertexStreamDescriptor::AddElement(Illusion::VertexStreamDescriptor *this, Illusion::VertexStreamElementUsage usage, Illusion::VertexSteamElementType type, int stream_num, UFG::qVector4 *default_value)
{
  signed __int64 v5; // rdi
  __int64 v6; // rsi
  int v7; // ebx
  Illusion::VertexStreamDescriptor *v8; // rbp
  signed __int64 v9; // rdx
  __int64 v10; // rax
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  Illusion::VertexStreamElement v14; // [rsp+30h] [rbp-38h]

  v5 = this->mTotalElements;
  v6 = stream_num;
  v7 = this->mStreamNumElements[stream_num];
  v8 = this;
  Illusion::VertexStreamElement::VertexStreamElement(
    &v14,
    usage,
    type,
    stream_num,
    this->mStreamSizes[stream_num],
    default_value);
  v9 = v5;
  v8->mElements[v9].usage = *(_DWORD *)v10;
  v8->mElements[v9].type = *(_DWORD *)(v10 + 4);
  v8->mElements[v9].stream = *(_WORD *)(v10 + 8);
  v8->mElements[v9].offset = *(_DWORD *)(v10 + 12);
  v8->mElements[v9].size = *(_DWORD *)(v10 + 16);
  v11 = *(float *)(v10 + 24);
  v12 = *(float *)(v10 + 28);
  v13 = *(float *)(v10 + 32);
  v8->mElements[v9].mDefault.x = *(float *)(v10 + 20);
  v8->mElements[v9].mDefault.y = v11;
  v8->mElements[v9].mDefault.z = v12;
  v8->mElements[v9].mDefault.w = v13;
  v8->mStreamSizes[v6] += v8->mElements[v5].size;
  v8->mTotalSize += v8->mElements[v5].size;
  v8->mStreamNumElements[v6] = v7 + 1;
  v8->mTotalElements = v5 + 1;
}

// File Line: 238
// RVA: 0x927B0
__int64 __fastcall Illusion::VertexStreamDescriptor::GetTotalElements(Illusion::VertexStreamDescriptor *this)
{
  return (unsigned int)this->mTotalElements;
}

// File Line: 255
// RVA: 0x92790
__int64 __fastcall Illusion::VertexStreamDescriptor::GetStreamSize(Illusion::VertexStreamDescriptor *this, int stream_num)
{
  __int64 result; // rax

  if ( stream_num == -1 )
    result = (unsigned int)this->mTotalSize;
  else
    result = (unsigned int)this->mStreamSizes[stream_num];
  return result;
}

// File Line: 263
// RVA: 0x92330
Illusion::VertexStreamElement *__fastcall Illusion::VertexStreamDescriptor::GetElement(Illusion::VertexStreamDescriptor *this, int index, int stream_num)
{
  int v3; // ebx
  Illusion::VertexStreamDescriptor *v4; // r10
  __int64 v6; // r11
  int v7; // er9
  __int64 v8; // r8
  __int16 *v9; // rcx

  v3 = stream_num;
  v4 = this;
  if ( stream_num == -1 )
  {
    if ( index < this->mTotalElements )
      return (Illusion::VertexStreamElement *)((char *)this + 36 * (index + 1i64));
    return 0i64;
  }
  v6 = this->mTotalElements;
  v7 = 0;
  v8 = 0i64;
  if ( v6 <= 0 )
    return 0i64;
  v9 = &this->mElements[0].stream;
  while ( *v9 != v3 )
  {
LABEL_9:
    ++v8;
    ++v7;
    v9 += 18;
    if ( v8 >= v6 )
      return 0i64;
  }
  if ( index )
  {
    --index;
    goto LABEL_9;
  }
  return (Illusion::VertexStreamElement *)((char *)v4 + 36 * (v7 + 1i64));
}

// File Line: 521
// RVA: 0x959E0
void __fastcall Illusion::VertexStreamDescriptor::SetStreamRuntimeFlag(Illusion::VertexStreamDescriptor *this, int stream_num)
{
  this->mStreamRuntimeFlags |= 1 << stream_num;
}

// File Line: 534
// RVA: 0x957E0
void __fastcall Illusion::VertexStreamDescriptor::SetIndexStreamMultiplier(Illusion::VertexStreamDescriptor *this, int mult)
{
  this->mIndexStreamMultiplier = mult;
}

// File Line: 545
// RVA: 0x957D0
void __fastcall Illusion::VertexStreamDescriptor::SetIndexStreamAsVertexStream(Illusion::VertexStreamDescriptor *this)
{
  this->mIndexStreamAsVertexStream = 1;
}

