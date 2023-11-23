// File Line: 67
// RVA: 0x8D2C0
void __fastcall Illusion::VertexStreamElement::VertexStreamElement(
        Illusion::VertexStreamElement *this,
        Illusion::VertexStreamElementUsage _usage,
        Illusion::VertexSteamElementType _type,
        __int16 _stream,
        int _offset,
        UFG::qVector4 *default_value)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float w; // xmm2_4

  this->usage = _usage;
  this->type = _type;
  this->stream = _stream;
  this->offset = _offset;
  switch ( _type )
  {
    case VERTEX_TYPE_FLOAT3:
      this->size = 12;
      break;
    case VERTEX_TYPE_FLOAT4:
      this->size = 16;
      break;
    case VERTEX_TYPE_HALF2:
    case VERTEX_TYPE_UBYTE4:
    case VERTEX_TYPE_COLOR4:
    case VERTEX_TYPE_UBYTE4N:
    case VERTEX_TYPE_11_11_10N:
    case VERTEX_TYPE_SINT16_2:
    case VERTEX_TYPE_UINT1:
    case VERTEX_TYPE_UBYTE4_DELTA:
    case VERTEX_TYPE_BYTE4N:
      this->size = 4;
      break;
    case VERTEX_TYPE_HALF4:
    case VERTEX_TYPE_SHORT4:
    case VERTEX_TYPE_SHORT4N:
    case VERTEX_TYPE_SHORT4_FIXED4_12:
    case VERTEX_TYPE_SHORT4_FIXED8_8:
      this->size = 8;
      break;
    case VERTEX_TYPE_HALF3:
      this->size = 6;
      break;
    default:
      this->size = 0;
      break;
  }
  if ( default_value )
  {
    y = default_value->y;
    z = default_value->z;
    w = default_value->w;
    this->mDefault.x = default_value->x;
    this->mDefault.y = y;
    this->mDefault.z = z;
    this->mDefault.w = w;
    return;
  }
  if ( _usage > VERTEX_ELEMENT_POSITION )
  {
    if ( _usage <= VERTEX_ELEMENT_TANGENT )
    {
      this->mDefault.z = 1.0;
      this->mDefault.w = 1.0;
      *(_QWORD *)&this->mDefault.x = 0i64;
      return;
    }
    if ( _usage <= VERTEX_ELEMENT_COLOR1 )
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
  if ( (_S1_14 & 1) == 0 )
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
void __fastcall Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
        Illusion::VertexStreamDescriptor *this,
        const char *name,
        unsigned int name_uid)
{
  UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *v4; // rbx
  UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *mPrev; // rax

  v4 = &this->UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor>;
  this->mPrev = &this->UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor>;
  this->mNext = &this->UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor>;
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Illusion::VertexStreamDescriptor::`vftable;
  this->mName = name;
  this->mNameUID = name_uid;
  *(_QWORD *)&this->mTotalElements = 0i64;
  this->mStreamRuntimeFlags = 0;
  this->mIndexStreamMultiplier = 1;
  this->mIndexStreamAsVertexStream = 0;
  UFG::qMemSet(this->mElements, 0, 0x240u);
  UFG::qMemSet(this->mStreamNumElements, 0, 0x10u);
  UFG::qMemSet(this->mStreamSizes, 0, 0x10u);
  if ( (_S1_14 & 1) == 0 )
  {
    _S1_14 |= 1u;
    sVertexStreamDescriptors.mNode.mPrev = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)&sVertexStreamDescriptors;
    sVertexStreamDescriptors.mNode.mNext = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)&sVertexStreamDescriptors;
    atexit(Illusion::VertexStreamDescriptor::GetStreamDescriptors_::_2_::_dynamic_atexit_destructor_for__sVertexStreamDescriptors__);
  }
  Illusion::gVertexStreamDescriptors = &sVertexStreamDescriptors;
  mPrev = sVertexStreamDescriptors.mNode.mPrev;
  sVertexStreamDescriptors.mNode.mPrev->mNext = v4;
  v4->mPrev = mPrev;
  v4->mNext = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)&sVertexStreamDescriptors;
  sVertexStreamDescriptors.mNode.mPrev = v4;
}

// File Line: 204
// RVA: 0x8DA20
void __fastcall Illusion::VertexStreamDescriptor::~VertexStreamDescriptor(Illusion::VertexStreamDescriptor *this)
{
  Illusion::VertexStreamDescriptor *v1; // rbx
  Illusion::VertexStreamDescriptorVtbl *vfptr; // rcx
  UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *mPrev; // rax
  Illusion::VertexStreamDescriptorVtbl *v4; // rcx
  UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *v5; // rax

  v1 = this;
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Illusion::VertexStreamDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::GetStreamDescriptors();
  v1 = (Illusion::VertexStreamDescriptor *)((char *)v1 + 8);
  vfptr = v1->vfptr;
  mPrev = v1->mPrev;
  vfptr[1].ApplyUserRemapping = (void (__fastcall *)(Illusion::VertexStreamDescriptor *, UFG::qVector4 *))mPrev;
  mPrev->mPrev = (UFG::qNode<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor> *)vfptr;
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
void __fastcall Illusion::VertexStreamDescriptor::AddElement(
        Illusion::VertexStreamDescriptor *this,
        Illusion::VertexStreamElementUsage usage,
        Illusion::VertexSteamElementType type,
        int stream_num,
        UFG::qVector4 *default_value)
{
  __int64 mTotalElements; // rdi
  __int64 v6; // rsi
  int v7; // ebx
  __int64 v9; // rdx
  __int64 v10; // rax
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  Illusion::VertexStreamElement v14; // [rsp+30h] [rbp-38h] BYREF

  mTotalElements = this->mTotalElements;
  v6 = stream_num;
  v7 = this->mStreamNumElements[stream_num];
  Illusion::VertexStreamElement::VertexStreamElement(
    &v14,
    usage,
    type,
    stream_num,
    this->mStreamSizes[stream_num],
    default_value);
  v9 = mTotalElements;
  this->mElements[v9].usage = *(_DWORD *)v10;
  this->mElements[v9].type = *(_DWORD *)(v10 + 4);
  this->mElements[v9].stream = *(_WORD *)(v10 + 8);
  this->mElements[v9].offset = *(_DWORD *)(v10 + 12);
  this->mElements[v9].size = *(_DWORD *)(v10 + 16);
  v11 = *(float *)(v10 + 24);
  v12 = *(float *)(v10 + 28);
  v13 = *(float *)(v10 + 32);
  this->mElements[v9].mDefault.x = *(float *)(v10 + 20);
  this->mElements[v9].mDefault.y = v11;
  this->mElements[v9].mDefault.z = v12;
  this->mElements[v9].mDefault.w = v13;
  this->mStreamSizes[v6] += this->mElements[mTotalElements].size;
  this->mTotalSize += this->mElements[mTotalElements].size;
  this->mStreamNumElements[v6] = v7 + 1;
  this->mTotalElements = mTotalElements + 1;
}

// File Line: 238
// RVA: 0x927B0
__int64 __fastcall Illusion::VertexStreamDescriptor::GetTotalElements(Illusion::VertexStreamDescriptor *this)
{
  return (unsigned int)this->mTotalElements;
}

// File Line: 255
// RVA: 0x92790
__int64 __fastcall Illusion::VertexStreamDescriptor::GetStreamSize(
        Illusion::VertexStreamDescriptor *this,
        int stream_num)
{
  if ( stream_num == -1 )
    return (unsigned int)this->mTotalSize;
  else
    return (unsigned int)this->mStreamSizes[stream_num];
}

// File Line: 263
// RVA: 0x92330
Illusion::VertexStreamElement *__fastcall Illusion::VertexStreamDescriptor::GetElement(
        Illusion::VertexStreamDescriptor *this,
        int index,
        int stream_num)
{
  __int64 mTotalElements; // r11
  int v7; // r9d
  __int64 v8; // r8
  __int16 *i; // rcx

  if ( stream_num == -1 )
  {
    if ( index < this->mTotalElements )
      return &this->mElements[index];
    return 0i64;
  }
  mTotalElements = this->mTotalElements;
  v7 = 0;
  v8 = 0i64;
  if ( mTotalElements <= 0 )
    return 0i64;
  for ( i = &this->mElements[0].stream; *i != stream_num; i += 18 )
  {
LABEL_9:
    ++v8;
    ++v7;
    if ( v8 >= mTotalElements )
      return 0i64;
  }
  if ( index )
  {
    --index;
    goto LABEL_9;
  }
  return &this->mElements[v7];
}

// File Line: 521
// RVA: 0x959E0
void __fastcall Illusion::VertexStreamDescriptor::SetStreamRuntimeFlag(
        Illusion::VertexStreamDescriptor *this,
        char stream_num)
{
  this->mStreamRuntimeFlags |= 1 << stream_num;
}

// File Line: 534
// RVA: 0x957E0
void __fastcall Illusion::VertexStreamDescriptor::SetIndexStreamMultiplier(
        Illusion::VertexStreamDescriptor *this,
        int mult)
{
  this->mIndexStreamMultiplier = mult;
}

// File Line: 545
// RVA: 0x957D0
void __fastcall Illusion::VertexStreamDescriptor::SetIndexStreamAsVertexStream(Illusion::VertexStreamDescriptor *this)
{
  this->mIndexStreamAsVertexStream = 1;
}

