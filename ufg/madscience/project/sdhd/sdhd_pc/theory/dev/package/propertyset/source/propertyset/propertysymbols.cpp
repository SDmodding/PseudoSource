// File Line: 75
// RVA: 0x1FA1E0
void MakeSureHashesCalculated(void)
{
  unsigned int i; // [rsp+20h] [rbp-18h]

  if ( !done )
  {
    for ( i = 0; i < 0x1C; ++i )
      dataTypeMap[i].mXMLTagHashUpper = UFG::qStringHashUpper32(dataTypeMap[i].mpszXMLTag, 0xFFFFFFFF);
    done = 1;
  }
}

// File Line: 90
// RVA: 0x1F8460
const char *__fastcall GetStringFromPropertySetType(ePropertyType eDataType)
{
  unsigned int i; // [rsp+20h] [rbp-18h]

  for ( i = 0; i < 0x1C; ++i )
  {
    if ( dataTypeMap[i].mDataType == eDataType )
      return dataTypeMap[i].mpszXMLTag;
  }
  UFG::qPrintf("Failed to get Property String for DataType value [%d]\n", (unsigned int)eDataType);
  return 0i64;
}

// File Line: 108
// RVA: 0x1F7B70
signed __int64 __fastcall GetPropertySetDataTypeFromString(const char *pszDataType)
{
  unsigned int i; // [rsp+20h] [rbp-18h]
  int v3; // [rsp+24h] [rbp-14h]
  char *str; // [rsp+40h] [rbp+8h]

  str = (char *)pszDataType;
  MakeSureHashesCalculated();
  v3 = UFG::qStringHashUpper32(str, 0xFFFFFFFF);
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
  float v2; // ST40_4
  signed __int64 v3; // ST60_8
  float v4; // ST58_4
  float v5; // ST44_4
  float *v6; // ST28_8
  float v7; // ST38_4
  float v8; // ST68_4
  float v9; // ST3C_4
  qPropertySetVariant *v10; // [rsp+90h] [rbp+8h]
  qPropertySetVariant *v11; // [rsp+98h] [rbp+10h]

  v11 = other;
  v10 = this;
  qPropertySetVariant::Clear(this);
  v10->meType = v11->meType;
  switch ( v11->meType )
  {
    case 0:
      v10->mValueI8 = v11->mValueI8;
      break;
    case 1:
      v10->mValueI16 = v11->mValueI16;
      break;
    case 2:
      v10->mValueI32 = v11->mValueI32;
      break;
    case 3:
      v10->mValueI64 = v11->mValueI64;
      break;
    case 4:
      v10->16 = v11->16;
      break;
    case 5:
      v10->mValueI8 = v11->mValueI8;
      break;
    case 6:
      v10->mValueI16 = v11->mValueI16;
      break;
    case 7:
      v10->mValueI32 = v11->mValueI32;
      break;
    case 8:
      v10->mValueI64 = v11->mValueI64;
      break;
    case 9:
      v10->mValueI8 = v11->mValueI8;
      break;
    case 0xA:
      v10->mValueI32 = v11->mValueI32;
      break;
    case 0xB:
    case 0xC:
      UFG::qString::operator=(&v10->mValueString, &v11->mValueString);
      break;
    case 0x11:
      v2 = v11->mValueVector2.y;
      v10->mValueVector2.x = v11->mValueVector2.x;
      v10->mValueVector2.y = v2;
      break;
    case 0x12:
      v3 = (signed __int64)&v10->mValueVector3;
      v4 = v11->mValueVector3.y;
      v5 = v11->mValueVector3.z;
      v10->mValueVector3.x = v11->mValueVector3.x;
      *(float *)(v3 + 4) = v4;
      *(float *)(v3 + 8) = v5;
      break;
    case 0x13:
      v6 = &v10->mValueVector4.x;
      v7 = v11->mValueVector4.y;
      v8 = v11->mValueVector4.z;
      v9 = v11->mValueVector4.w;
      v10->mValueVector4.x = v11->mValueVector4.x;
      v6[1] = v7;
      v6[2] = v8;
      v6[3] = v9;
      break;
    case 0x16:
      UFG::qSymbol::qSymbol(&v10->mValueSymbol, &v11->mValueSymbol);
      break;
    case 0x17:
      UFG::qSymbol::qSymbol((UFG::qSymbol *)&v10->mValueSymbolUC, (UFG::qSymbol *)&v11->mValueSymbolUC);
      break;
    case 0x18:
      UFG::qWiseSymbol::operator=(&v10->mValueWiseSymbol, &v11->mValueWiseSymbol);
      break;
    default:
      return;
  }
}

// File Line: 183
// RVA: 0x1EF180
bool __fastcall qPropertySetVariant::operator==(qPropertySetVariant *this, qPropertySetVariant *other)
{
  _BOOL8 v2; // rax
  char *text_b; // ST90_8
  const char *v4; // rax
  bool v6; // [rsp+30h] [rbp-78h]
  bool v7; // [rsp+38h] [rbp-70h]
  bool v8; // [rsp+40h] [rbp-68h]
  qPropertySetVariant *v9; // [rsp+B0h] [rbp+8h]

  v9 = this;
  switch ( this->meType )
  {
    case 0:
      LOBYTE(v2) = this->mValueI8 == other->mValueI8;
      break;
    case 1:
      LOBYTE(v2) = this->mValueI16 == other->mValueI16;
      break;
    case 2:
      LOBYTE(v2) = this->mValueI32 == other->mValueI32;
      break;
    case 3:
      LOBYTE(v2) = this->mValueI64 == other->mValueI64;
      break;
    case 4:
      LOBYTE(v2) = 0;
      break;
    case 5:
      LOBYTE(v2) = this->mValueI8 == other->mValueI8;
      break;
    case 6:
      LOBYTE(v2) = this->mValueI128.m128_u16[0] == other->mValueI128.m128_u16[0];
      break;
    case 7:
      LOBYTE(v2) = this->mValueI32 == other->mValueI32;
      break;
    case 8:
      LOBYTE(v2) = this->mValueI64 == other->mValueI64;
      break;
    case 9:
      LOBYTE(v2) = this->mValueI8 == other->mValueI8;
      break;
    case 0xA:
      LOBYTE(v2) = other->mValueI128.m128_f32[0] == this->mValueI128.m128_f32[0];
      break;
    case 0xB:
      LOBYTE(v2) = *(double *)&other->mValueI64 == *(double *)&this->mValueI64;
      break;
    case 0xC:
      text_b = (char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&other->mValueString);
      v4 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&v9->mValueString);
      v2 = (unsigned int)UFG::qStringCompare(v4, text_b, -1) == 0;
      break;
    case 0x11:
      v6 = other->mValueVector2.x == this->mValueVector2.x && other->mValueVector2.y == this->mValueVector2.y;
      LOBYTE(v2) = v6;
      break;
    case 0x12:
      v7 = other->mValueVector3.x == this->mValueVector3.x
        && other->mValueVector3.y == this->mValueVector3.y
        && other->mValueVector3.z == this->mValueVector3.z;
      LOBYTE(v2) = v7;
      break;
    case 0x13:
      v8 = other->mValueVector4.x == this->mValueVector4.x
        && other->mValueVector4.y == this->mValueVector4.y
        && other->mValueVector4.z == this->mValueVector4.z
        && other->mValueVector4.w == this->mValueVector4.w;
      LOBYTE(v2) = v8;
      break;
    case 0x16:
      LOBYTE(v2) = UFG::qSymbol::operator==(&this->mValueSymbol, &other->mValueSymbol);
      break;
    case 0x17:
      LOBYTE(v2) = UFG::qSymbol::operator==(
                     (UFG::qSymbol *)&this->mValueSymbolUC,
                     (UFG::qSymbol *)&other->mValueSymbolUC);
      break;
    case 0x18:
      LOBYTE(v2) = UFG::qSymbol::operator==(
                     (UFG::qSymbol *)&this->mValueWiseSymbol,
                     (UFG::qSymbol *)&other->mValueWiseSymbol);
      break;
    default:
      LOBYTE(v2) = 0;
      break;
  }
  return v2;
}

// File Line: 237
// RVA: 0x1F23F0
void __fastcall qPropertySetVariant::Clear(qPropertySetVariant *this)
{
  UFG::qString *v1; // rax
  UFG::qString v2; // [rsp+38h] [rbp-30h]
  qPropertySetVariant *v3; // [rsp+70h] [rbp+8h]

  v3 = this;
  UFG::qString::qString(&v2);
  UFG::qString::operator=(&v3->mValueString, v1);
  UFG::qString::~qString(&v2);
}

// File Line: 242
// RVA: 0x1FF080
void __fastcall qPropertySetVariant::ToString(qPropertySetVariant *this, UFG::qString *value)
{
  char *v2; // rax
  char *v3; // rax
  const char *v4; // rax
  UFG::qString *v5; // [rsp+68h] [rbp+10h]

  v5 = value;
  switch ( this->meType )
  {
    case 0:
      UFG::qString::Format(value, "%d", (unsigned int)this->mValueI8);
      break;
    case 1:
      UFG::qString::Format(value, "%d", (unsigned int)this->mValueI16);
      break;
    case 2:
      UFG::qString::Format(value, "%d", this->mValueI128.m128_u32[0]);
      break;
    case 3:
      UFG::qString::Format(value, "%d64", this->mValueI128.m128_u32[0]);
      break;
    case 5:
      UFG::qString::Format(value, "%u", (unsigned __int8)this->mValueI8);
      break;
    case 6:
      UFG::qString::Format(value, "%u", this->mValueI128.m128_u16[0]);
      break;
    case 7:
      UFG::qString::Format(value, "%u", this->mValueI128.m128_u32[0]);
      break;
    case 8:
      UFG::qString::Format(value, "%u64", this->mValueI128.m128_u32[0]);
      break;
    case 9:
      if ( this->mValueI8 )
        UFG::qString::operator=(value, "true");
      else
        UFG::qString::operator=(value, "false");
      break;
    case 0xA:
      UFG::qString::Format(value, "%f", this->mValueI128.m128_f32[0]);
      break;
    case 0xB:
    case 0xC:
      UFG::qString::operator=(value, &this->mValueString);
      break;
    case 0x11:
      UFG::qString::Format(value, "%f,%f", this->mValueVector2.x, this->mValueVector2.y);
      break;
    case 0x12:
      UFG::qString::Format(value, "%f,%f,%f", this->mValueVector3.x, this->mValueVector3.y, this->mValueVector3.z);
      break;
    case 0x13:
      UFG::qString::Format(
        value,
        "%f,%f,%f,%f",
        this->mValueVector4.x,
        this->mValueVector4.y,
        this->mValueVector4.z,
        this->mValueVector4.w);
      break;
    case 0x14:
      UFG::qString::operator=(value, "?TODO?");
      break;
    case 0x15:
    case 0x16:
      v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mValueSymbol);
      UFG::qString::operator=(v5, v2);
      break;
    case 0x17:
      v3 = UFG::qSymbol::as_cstr_dbg(&this->mValueSymbolUC);
      UFG::qString::operator=(v5, v3);
      break;
    case 0x18:
      v4 = UFG::qWiseSymbol::as_cstr_dbg(&this->mValueWiseSymbol);
      UFG::qString::operator=(v5, v4);
      break;
    case 0x1B:
      UFG::qString::operator=(value, "?TODO?");
      break;
    case 0x1C:
      UFG::qString::operator=(value, "?TODO?");
      break;
    case 0x1D:
      UFG::qString::operator=(value, "?INVALID?");
      break;
    default:
      return;
  }
}

// File Line: 348
// RVA: 0x1FD0A0
void __fastcall qPropertySetVariant::SetFromString(qPropertySetVariant *this, UFG::qString *value, ePropertyType eType)
{
  const char *v3; // rax
  const char *v4; // rax
  const char *v5; // rax
  const char *v6; // rax
  const char *v7; // rax
  const char *v8; // rax
  const char *v9; // rax
  const char *v10; // rax
  const char *v11; // rax
  const char *v12; // rax
  const char *v13; // rax
  const char *v14; // rax
  const char *v15; // rax
  UFG::qSymbol result; // [rsp+24h] [rbp-54h]
  UFG::qSymbolUC v17; // [rsp+28h] [rbp-50h]
  UFG::qWiseSymbol v18; // [rsp+2Ch] [rbp-4Ch]
  UFG::qSymbol *source; // [rsp+30h] [rbp-48h]
  UFG::qSymbol *v20; // [rsp+38h] [rbp-40h]
  UFG::qWiseSymbol *v21; // [rsp+40h] [rbp-38h]
  UFG::qSymbol *v22; // [rsp+48h] [rbp-30h]
  UFG::qWiseSymbol *v23; // [rsp+50h] [rbp-28h]
  UFG::qSymbol *v24; // [rsp+58h] [rbp-20h]
  __int64 v25; // [rsp+60h] [rbp-18h]
  qPropertySetVariant *v26; // [rsp+80h] [rbp+8h]

  v26 = this;
  v25 = -2i64;
  this->meType = eType;
  switch ( eType )
  {
    case 0:
      v3 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI8 = UFG::qToInt32(v3, 0);
      break;
    case 1:
      v4 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI16 = UFG::qToInt32(v4, 0);
      break;
    case 2:
      v5 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI32 = UFG::qToInt32(v5, 0);
      break;
    case 3:
      v6 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI64 = UFG::qToInt64(v6, 0i64);
      break;
    case 4:
      return;
    case 5:
      v7 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI8 = UFG::qToUInt32(v7, 0);
      break;
    case 6:
      v8 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI16 = UFG::qToUInt32(v8, 0);
      break;
    case 7:
      v9 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI32 = UFG::qToUInt32(v9, 0);
      break;
    case 8:
      v10 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI64 = UFG::qToUInt64(v10, 0i64);
      break;
    case 9:
      v11 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI8 = UFG::qToBool(v11, 0);
      break;
    case 10:
      v12 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v26->mValueI128.m128_f32[0] = UFG::qToFloat(v12, 0.0);
      break;
    case 11:
    case 12:
      UFG::qString::operator=(&this->mValueString, value);
      break;
    case 22:
      v13 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v24 = UFG::qSymbol::create_from_string(&result, v13);
      source = v24;
      UFG::qSymbol::qSymbol(&v26->mValueSymbol, v24);
      _((AMD_HD3D *)&result);
      break;
    case 23:
      v14 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v22 = (UFG::qSymbol *)UFG::qSymbolUC::create_from_string(&v17, v14);
      v20 = v22;
      UFG::qSymbol::qSymbol((UFG::qSymbol *)&v26->mValueSymbolUC, v22);
      _((AMD_HD3D *)&v17);
      break;
    case 24:
      v15 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)value);
      v21 = UFG::qWiseSymbol::create_from_string(&v18, v15);
      v23 = v21;
      UFG::qWiseSymbol::operator=(&v26->mValueWiseSymbol, v21);
      UFG::qWiseSymbol::~qWiseSymbol(&v18);
      break;
    default:
      this->meType = 29;
      break;
  }
}

// File Line: 401
// RVA: 0x1FCA70
void __fastcall qPropertySetVariant::Set(qPropertySetVariant *this, const void *dataPtr, ePropertyType eType)
{
  float v3; // ST60_4
  UFG::qVector3 *v4; // ST38_8
  float v5; // ST44_4
  float v6; // ST54_4
  _DWORD *v7; // ST28_8
  int v8; // ST5C_4
  int v9; // ST40_4
  int v10; // ST48_4
  _OWORD *v11; // ST30_8
  __int128 v12; // STB0_16
  __int128 v13; // STD0_16
  __int128 v14; // STF0_16

  this->meType = eType;
  switch ( eType )
  {
    case 0:
      this->mValueI8 = *(_BYTE *)dataPtr;
      break;
    case 1:
      this->mValueI16 = *(_WORD *)dataPtr;
      break;
    case 2:
      this->mValueI32 = *(_DWORD *)dataPtr;
      break;
    case 3:
      this->mValueI64 = *(_QWORD *)dataPtr;
      break;
    case 5:
      this->mValueI8 = *(_BYTE *)dataPtr;
      break;
    case 6:
      this->mValueI16 = *(_WORD *)dataPtr;
      break;
    case 7:
      this->mValueI32 = *(_DWORD *)dataPtr;
      break;
    case 8:
      this->mValueI64 = *(_QWORD *)dataPtr;
      break;
    case 9:
      this->mValueI8 = *(_BYTE *)dataPtr != 0;
      break;
    case 10:
      this->mValueI32 = *(_DWORD *)dataPtr;
      break;
    case 11:
      this->mValueI64 = *(_QWORD *)dataPtr;
      break;
    case 12:
      if ( *(_QWORD *)dataPtr )
        UFG::qString::operator=(&this->mValueString, (const char *)dataPtr + *(_QWORD *)dataPtr);
      else
        UFG::qString::operator=(&this->mValueString, 0i64);
      break;
    case 17:
      v3 = *((float *)dataPtr + 1);
      this->mValueVector2.x = *(float *)dataPtr;
      this->mValueVector2.y = v3;
      break;
    case 18:
      v4 = &this->mValueVector3;
      v5 = *((float *)dataPtr + 1);
      v6 = *((float *)dataPtr + 2);
      this->mValueVector3.x = *(float *)dataPtr;
      v4->y = v5;
      v4->z = v6;
      break;
    case 19:
      v7 = (_DWORD *)&this->mValueVector4.x;
      v8 = *((_DWORD *)dataPtr + 1);
      v9 = *((_DWORD *)dataPtr + 2);
      v10 = *((_DWORD *)dataPtr + 3);
      this->mValueVector4.x = *(float *)dataPtr;
      v7[1] = v8;
      v7[2] = v9;
      v7[3] = v10;
      break;
    case 20:
      v11 = (_OWORD *)&this->mValueMatrix44.v0.x;
      v12 = *((_OWORD *)dataPtr + 1);
      v13 = *((_OWORD *)dataPtr + 2);
      v14 = *((_OWORD *)dataPtr + 3);
      this->mValueMatrix44.v0 = *(UFG::qVector4 *)dataPtr;
      v11[1] = v12;
      v11[2] = v13;
      v11[3] = v14;
      break;
    case 21:
    case 22:
      UFG::qSymbol::qSymbol(&this->mValueSymbol, (UFG::qSymbol *)dataPtr);
      break;
    case 23:
      UFG::qSymbol::qSymbol((UFG::qSymbol *)&this->mValueSymbolUC, (UFG::qSymbol *)dataPtr);
      break;
    case 24:
      UFG::qWiseSymbol::operator=(&this->mValueWiseSymbol, (UFG::qWiseSymbol *)dataPtr);
      break;
    default:
      return;
  }
}

