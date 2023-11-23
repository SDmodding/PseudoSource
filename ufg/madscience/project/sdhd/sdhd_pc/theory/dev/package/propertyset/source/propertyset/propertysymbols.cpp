// File Line: 75
// RVA: 0x1FA1E0
void MakeSureHashesCalculated(void)
{
  unsigned int i; // [rsp+20h] [rbp-18h]

  if ( !done )
  {
    for ( i = 0; i < 0x1C; ++i )
      dataTypeMap[i].mXMLTagHashUpper = UFG::qStringHashUpper32(dataTypeMap[i].mpszXMLTag, -1);
    done = 1;
  }
}

// File Line: 90
// RVA: 0x1F8460
const char *__fastcall GetStringFromPropertySetType(unsigned int eDataType)
{
  unsigned int i; // [rsp+20h] [rbp-18h]

  for ( i = 0; i < 0x1C; ++i )
  {
    if ( dataTypeMap[i].mDataType == eDataType )
      return dataTypeMap[i].mpszXMLTag;
  }
  UFG::qPrintf("Failed to get Property String for DataType value [%d]\n", eDataType);
  return 0i64;
}

// File Line: 108
// RVA: 0x1F7B70
__int64 __fastcall GetPropertySetDataTypeFromString(const char *pszDataType)
{
  unsigned int i; // [rsp+20h] [rbp-18h]
  int v3; // [rsp+24h] [rbp-14h]

  MakeSureHashesCalculated();
  v3 = UFG::qStringHashUpper32(pszDataType, -1);
  for ( i = 0; i < 0x1C; ++i )
  {
    if ( dataTypeMap[i].mXMLTagHashUpper == v3 )
      return (unsigned int)dataTypeMap[i].mDataType;
  }
  return 29i64;
}

// File Line: 127
// RVA: 0x1EED30
void __fastcall qPropertySetVariant::operator=(qPropertySetVariant *this, qPropertySetVariant *other)
{
  float v2; // [rsp+38h] [rbp-50h]
  float w; // [rsp+3Ch] [rbp-4Ch]
  float y; // [rsp+40h] [rbp-48h]
  float z; // [rsp+44h] [rbp-44h]
  float v6; // [rsp+58h] [rbp-30h]
  float v7; // [rsp+68h] [rbp-20h]

  qPropertySetVariant::Clear(this);
  this->meType = other->meType;
  switch ( other->meType )
  {
    case UID_int8:
      this->mValueI8 = other->mValueI8;
      break;
    case UID_int16:
      this->mValueI16 = other->mValueI16;
      break;
    case UID_int32:
      this->mValueI32 = other->mValueI32;
      break;
    case UID_int64:
      this->mValueI64 = other->mValueI64;
      break;
    case UID_int128:
      this->16 = other->16;
      break;
    case UID_uint8:
      this->mValueI8 = other->mValueI8;
      break;
    case UID_uint16:
      this->mValueI16 = other->mValueI16;
      break;
    case UID_uint32:
      this->mValueI32 = other->mValueI32;
      break;
    case UID_uint64:
      this->mValueI64 = other->mValueI64;
      break;
    case UID_bool:
      this->mValueI8 = other->mValueI8;
      break;
    case UID_float:
      this->mValueI32 = other->mValueI32;
      break;
    case UID_double:
    case UID_string:
      UFG::qString::operator=(&this->mValueString, &other->mValueString);
      break;
    case UID_qVector2:
      y = other->mValueVector2.y;
      this->mValueVector2.x = other->mValueVector2.x;
      this->mValueVector2.y = y;
      break;
    case UID_qVector3:
      v6 = other->mValueVector3.y;
      z = other->mValueVector3.z;
      this->mValueVector3.x = other->mValueVector3.x;
      this->mValueVector3.y = v6;
      this->mValueVector3.z = z;
      break;
    case UID_qVector4:
      v2 = other->mValueVector4.y;
      v7 = other->mValueVector4.z;
      w = other->mValueVector4.w;
      this->mValueVector4.x = other->mValueVector4.x;
      this->mValueVector4.y = v2;
      this->mValueVector4.z = v7;
      this->mValueVector4.w = w;
      break;
    case UID_qSymbol:
      UFG::qSymbol::qSymbol(&this->mValueSymbol, &other->mValueSymbol);
      break;
    case UID_qSymbolUC:
      UFG::qSymbol::qSymbol((UFG::qSymbol *)&this->mValueSymbolUC, (UFG::qSymbol *)&other->mValueSymbolUC);
      break;
    case UID_qWiseSymbol:
      UFG::qWiseSymbol::operator=(&this->mValueWiseSymbol, &other->mValueWiseSymbol);
      break;
    default:
      return;
  }
}

// File Line: 183
// RVA: 0x1EF180
bool __fastcall qPropertySetVariant::operator==(qPropertySetVariant *this, qPropertySetVariant *other)
{
  bool result; // al
  const char *UsedSpace; // rax
  bool v4; // [rsp+30h] [rbp-78h]
  bool v5; // [rsp+38h] [rbp-70h]
  bool v6; // [rsp+40h] [rbp-68h]
  char *text_b; // [rsp+90h] [rbp-18h]

  switch ( this->meType )
  {
    case UID_int8:
      result = this->mValueI8 == other->mValueI8;
      break;
    case UID_int16:
      result = this->mValueI16 == other->mValueI16;
      break;
    case UID_int32:
      result = this->mValueI32 == other->mValueI32;
      break;
    case UID_int64:
      result = this->mValueI64 == other->mValueI64;
      break;
    case UID_int128:
      result = 0;
      break;
    case UID_uint8:
      result = this->mValueI8 == other->mValueI8;
      break;
    case UID_uint16:
      result = this->mValueI128.m128_u16[0] == other->mValueI128.m128_u16[0];
      break;
    case UID_uint32:
      result = this->mValueI32 == other->mValueI32;
      break;
    case UID_uint64:
      result = this->mValueI64 == other->mValueI64;
      break;
    case UID_bool:
      result = this->mValueI8 == other->mValueI8;
      break;
    case UID_float:
      result = other->mValueI128.m128_f32[0] == this->mValueI128.m128_f32[0];
      break;
    case UID_double:
      result = other->mValueDouble == this->mValueDouble;
      break;
    case UID_string:
      text_b = (char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&other->mValueString);
      UsedSpace = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&this->mValueString);
      result = (unsigned int)UFG::qStringCompare(UsedSpace, text_b, -1) == 0;
      break;
    case UID_qVector2:
      v4 = other->mValueVector2.x == this->mValueVector2.x && other->mValueVector2.y == this->mValueVector2.y;
      result = v4;
      break;
    case UID_qVector3:
      v5 = other->mValueVector3.x == this->mValueVector3.x
        && other->mValueVector3.y == this->mValueVector3.y
        && other->mValueVector3.z == this->mValueVector3.z;
      result = v5;
      break;
    case UID_qVector4:
      v6 = other->mValueVector4.x == this->mValueVector4.x
        && other->mValueVector4.y == this->mValueVector4.y
        && other->mValueVector4.z == this->mValueVector4.z
        && other->mValueVector4.w == this->mValueVector4.w;
      result = v6;
      break;
    case UID_qSymbol:
      result = UFG::qSymbol::operator==(&this->mValueSymbol, &other->mValueSymbol);
      break;
    case UID_qSymbolUC:
      result = UFG::qSymbol::operator==((UFG::qSymbol *)&this->mValueSymbolUC, (UFG::qSymbol *)&other->mValueSymbolUC);
      break;
    case UID_qWiseSymbol:
      result = UFG::qSymbol::operator==(
                 (UFG::qSymbol *)&this->mValueWiseSymbol,
                 (UFG::qSymbol *)&other->mValueWiseSymbol);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 237
// RVA: 0x1F23F0
void __fastcall qPropertySetVariant::Clear(qPropertySetVariant *this)
{
  UFG::qString *v1; // rax
  UFG::qString v2; // [rsp+38h] [rbp-30h] BYREF

  UFG::qString::qString(&v2);
  UFG::qString::operator=(&this->mValueString, v1);
  UFG::qString::~qString(&v2);
}

// File Line: 242
// RVA: 0x1FF080
void __fastcall qPropertySetVariant::ToString(qPropertySetVariant *this, UFG::qString *value)
{
  char *v2; // rax
  char *v3; // rax
  char *v4; // rax

  switch ( this->meType )
  {
    case UID_int8:
      UFG::qString::Format(value, "%d", (unsigned int)this->mValueI8);
      break;
    case UID_int16:
      UFG::qString::Format(value, "%d", (unsigned int)this->mValueI16);
      break;
    case UID_int32:
      UFG::qString::Format(value, "%d", this->mValueI128.m128_u32[0]);
      break;
    case UID_int64:
      UFG::qString::Format(value, "%d64", this->mValueI128.m128_u32[0]);
      break;
    case UID_uint8:
      UFG::qString::Format(value, "%u", (unsigned __int8)this->mValueI8);
      break;
    case UID_uint16:
      UFG::qString::Format(value, "%u", this->mValueI128.m128_u16[0]);
      break;
    case UID_uint32:
      UFG::qString::Format(value, "%u", this->mValueI128.m128_u32[0]);
      break;
    case UID_uint64:
      UFG::qString::Format(value, "%u64", this->mValueI128.m128_u32[0]);
      break;
    case UID_bool:
      if ( this->mValueI8 )
        UFG::qString::operator=(value, "true");
      else
        UFG::qString::operator=(value, "false");
      break;
    case UID_float:
      UFG::qString::Format(value, "%f", this->mValueI128.m128_f32[0]);
      break;
    case UID_double:
    case UID_string:
      UFG::qString::operator=(value, &this->mValueString);
      break;
    case UID_qVector2:
      UFG::qString::Format(value, "%f,%f", this->mValueVector2.x, this->mValueVector2.y);
      break;
    case UID_qVector3:
      UFG::qString::Format(value, "%f,%f,%f", this->mValueVector3.x, this->mValueVector3.y, this->mValueVector3.z);
      break;
    case UID_qVector4:
      UFG::qString::Format(
        value,
        "%f,%f,%f,%f",
        this->mValueVector4.x,
        this->mValueVector4.y,
        this->mValueVector4.z,
        this->mValueVector4.w);
      break;
    case UID_qMatrix44:
    case UID_TransRot:
    case UID_qTransQuat:
      UFG::qString::operator=(value, "?TODO?");
      break;
    case UID_qResHandle:
    case UID_qSymbol:
      v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mValueSymbol);
      UFG::qString::operator=(value, v2);
      break;
    case UID_qSymbolUC:
      v3 = UFG::qSymbol::as_cstr_dbg(&this->mValueSymbolUC);
      UFG::qString::operator=(value, v3);
      break;
    case UID_qWiseSymbol:
      v4 = UFG::qWiseSymbol::as_cstr_dbg(&this->mValueWiseSymbol);
      UFG::qString::operator=(value, v4);
      break;
    case UID_Invalid:
      UFG::qString::operator=(value, "?INVALID?");
      break;
    default:
      return;
  }
}

// File Line: 348
// RVA: 0x1FD0A0
void __fastcall qPropertySetVariant::SetFromString(
        qPropertySetVariant *this,
        hkMemoryResourceContainer *value,
        ePropertyType eType)
{
  const char *UsedSpace; // rax
  const char *v4; // rax
  const char *v5; // rax
  const char *v6; // rax
  const char *v7; // rax
  const char *v8; // rax
  const char *v9; // rax
  const char *v10; // rax
  char *v11; // rax
  const char *v12; // rax
  const char *v13; // rax
  const char *v14; // rax
  const char *v15; // rax
  UFG::qSymbol result; // [rsp+24h] [rbp-54h] BYREF
  AMD_HD3D v17; // [rsp+28h] [rbp-50h] BYREF
  IAmdDxExtQuadBufferStereo *v18; // [rsp+48h] [rbp-30h]
  UFG::qWiseSymbol *mExtension; // [rsp+50h] [rbp-28h]
  UFG::qSymbol *v20; // [rsp+58h] [rbp-20h]
  __int64 v21; // [rsp+60h] [rbp-18h]

  v21 = -2i64;
  this->meType = eType;
  switch ( eType )
  {
    case UID_int8:
      UsedSpace = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI8 = UFG::qToInt32(UsedSpace, 0);
      break;
    case UID_int16:
      v4 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI16 = UFG::qToInt32(v4, 0);
      break;
    case UID_int32:
      v5 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI32 = UFG::qToInt32(v5, 0);
      break;
    case UID_int64:
      v6 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI64 = UFG::qToInt64(v6, 0i64);
      break;
    case UID_int128:
      return;
    case UID_uint8:
      v7 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI8 = UFG::qToUInt32(v7, 0);
      break;
    case UID_uint16:
      v8 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI16 = UFG::qToUInt32(v8, 0);
      break;
    case UID_uint32:
      v9 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI32 = UFG::qToUInt32(v9, 0);
      break;
    case UID_uint64:
      v10 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI64 = UFG::qToUInt64(v10, 0i64);
      break;
    case UID_bool:
      v11 = (char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI8 = UFG::qToBool(v11, 0);
      break;
    case UID_float:
      v12 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      this->mValueI128.m128_f32[0] = UFG::qToFloat(v12, 0.0);
      break;
    case UID_double:
    case UID_string:
      UFG::qString::operator=(&this->mValueString, (UFG::qString *)value);
      break;
    case UID_qSymbol:
      v13 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      v20 = UFG::qSymbol::create_from_string(&result, v13);
      *(_QWORD *)&v17.mWidth = v20;
      UFG::qSymbol::qSymbol(&this->mValueSymbol, v20);
      _((AMD_HD3D *)&result);
      break;
    case UID_qSymbolUC:
      v14 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      v18 = (IAmdDxExtQuadBufferStereo *)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&v17, v14);
      v17.mStereo = v18;
      UFG::qSymbol::qSymbol((UFG::qSymbol *)&this->mValueSymbolUC, (UFG::qSymbol *)v18);
      _(&v17);
      break;
    case UID_qWiseSymbol:
      v15 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(value);
      v17.mExtension = (IAmdDxExt *)UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&v17.mLineOffset, v15);
      mExtension = (UFG::qWiseSymbol *)v17.mExtension;
      UFG::qWiseSymbol::operator=(&this->mValueWiseSymbol, (UFG::qWiseSymbol *)v17.mExtension);
      UFG::qWiseSymbol::~qWiseSymbol((UFG::qWiseSymbol *)&v17.mLineOffset);
      break;
    default:
      this->meType = UID_Invalid;
      break;
  }
}

// File Line: 401
// RVA: 0x1FCA70
void __fastcall qPropertySetVariant::Set(qPropertySetVariant *this, char *dataPtr, ePropertyType eType)
{
  float v3; // [rsp+40h] [rbp-C8h]
  float v4; // [rsp+44h] [rbp-C4h]
  float v5; // [rsp+48h] [rbp-C0h]
  float v6; // [rsp+54h] [rbp-B4h]
  float v7; // [rsp+5Ch] [rbp-ACh]
  float v8; // [rsp+60h] [rbp-A8h]
  UFG::qVector4 v9; // [rsp+B0h] [rbp-58h]
  UFG::qVector4 v10; // [rsp+D0h] [rbp-38h]
  UFG::qVector4 v11; // [rsp+F0h] [rbp-18h]

  this->meType = eType;
  switch ( eType )
  {
    case UID_int8:
      this->mValueI8 = *dataPtr;
      break;
    case UID_int16:
      this->mValueI16 = *(_WORD *)dataPtr;
      break;
    case UID_int32:
      this->mValueI32 = *(_DWORD *)dataPtr;
      break;
    case UID_int64:
      this->mValueI64 = *(_QWORD *)dataPtr;
      break;
    case UID_uint8:
      this->mValueI8 = *dataPtr;
      break;
    case UID_uint16:
      this->mValueI16 = *(_WORD *)dataPtr;
      break;
    case UID_uint32:
      this->mValueI32 = *(_DWORD *)dataPtr;
      break;
    case UID_uint64:
      this->mValueI64 = *(_QWORD *)dataPtr;
      break;
    case UID_bool:
      this->mValueI8 = *dataPtr != 0;
      break;
    case UID_float:
      this->mValueI32 = *(_DWORD *)dataPtr;
      break;
    case UID_double:
      this->mValueI64 = *(_QWORD *)dataPtr;
      break;
    case UID_string:
      if ( *(_QWORD *)dataPtr )
        UFG::qString::operator=(&this->mValueString, &dataPtr[*(_QWORD *)dataPtr]);
      else
        UFG::qString::operator=(&this->mValueString, 0i64);
      break;
    case UID_qVector2:
      v8 = *((float *)dataPtr + 1);
      this->mValueVector2.x = *(float *)dataPtr;
      this->mValueVector2.y = v8;
      break;
    case UID_qVector3:
      v4 = *((float *)dataPtr + 1);
      v6 = *((float *)dataPtr + 2);
      this->mValueVector3.x = *(float *)dataPtr;
      this->mValueVector3.y = v4;
      this->mValueVector3.z = v6;
      break;
    case UID_qVector4:
      v7 = *((float *)dataPtr + 1);
      v3 = *((float *)dataPtr + 2);
      v5 = *((float *)dataPtr + 3);
      this->mValueVector4.x = *(float *)dataPtr;
      this->mValueVector4.y = v7;
      this->mValueVector4.z = v3;
      this->mValueVector4.w = v5;
      break;
    case UID_qMatrix44:
      v9 = (UFG::qVector4)*((_OWORD *)dataPtr + 1);
      v10 = (UFG::qVector4)*((_OWORD *)dataPtr + 2);
      v11 = (UFG::qVector4)*((_OWORD *)dataPtr + 3);
      this->mValueMatrix44.v0 = *(UFG::qVector4 *)dataPtr;
      this->mValueMatrix44.v1 = v9;
      this->mValueMatrix44.v2 = v10;
      this->mValueMatrix44.v3 = v11;
      break;
    case UID_qResHandle:
    case UID_qSymbol:
      UFG::qSymbol::qSymbol(&this->mValueSymbol, (UFG::qSymbol *)dataPtr);
      break;
    case UID_qSymbolUC:
      UFG::qSymbol::qSymbol((UFG::qSymbol *)&this->mValueSymbolUC, (UFG::qSymbol *)dataPtr);
      break;
    case UID_qWiseSymbol:
      UFG::qWiseSymbol::operator=(&this->mValueWiseSymbol, (UFG::qWiseSymbol *)dataPtr);
      break;
    default:
      return;
  }
}

