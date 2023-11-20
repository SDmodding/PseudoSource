// File Line: 14
// RVA: 0x12FF720
void __fastcall hkClassMemberAccessor::connect(hkClassMemberAccessor *this, void *obj, hkClassMember *mem)
{
  __int64 v3; // rax

  v3 = mem->m_offset;
  this->m_member = mem;
  this->m_address = (char *)obj + v3;
}

// File Line: 23
// RVA: 0x12FF740
void __fastcall hkClassMemberAccessor::connect(hkClassMemberAccessor *this, void *obj, hkClass *klass, const char *memberName)
{
  char *v4; // rdi
  hkClassMemberAccessor *v5; // rbx
  hkClassMember *v6; // rax

  v4 = (char *)obj;
  v5 = this;
  this->m_address = 0i64;
  v6 = hkClass::getMemberByName(klass, memberName);
  v5->m_member = v6;
  if ( v6 )
    v5->m_address = &v4[v6->m_offset];
}

// File Line: 40
// RVA: 0x12FF340
void __fastcall hkClassMemberAccessor::hkClassMemberAccessor(hkClassMemberAccessor *this, void *obj, hkClassMember *mem)
{
  hkClassMemberAccessor::connect(this, obj, mem);
}

// File Line: 45
// RVA: 0x12FF360
void __fastcall hkClassMemberAccessor::hkClassMemberAccessor(hkClassMemberAccessor *this, hkVariant *var, const char *memberName)
{
  hkClassMemberAccessor::connect(this, var->m_object, var->m_class, memberName);
}

// File Line: 50
// RVA: 0x12FF390
void __fastcall hkClassMemberAccessor::hkClassMemberAccessor(hkClassMemberAccessor *this, void *obj, hkClass *klass, const char *memberName)
{
  hkClassMemberAccessor::connect(this, obj, klass, memberName);
}

// File Line: 55
// RVA: 0x12FF3B0
hkBool *__fastcall hkClassMemberAccessor::isOk(hkClassMemberAccessor *this, hkBool *result)
{
  result->m_bool = this->m_address != 0i64;
  return result;
}

// File Line: 60
// RVA: 0x12FF3E0
void *__fastcall hkClassMemberAccessor::asRaw(hkClassMemberAccessor *this)
{
  return this->m_address;
}

// File Line: 66
// RVA: 0x12FF3F0
void *__fastcall hkClassMemberAccessor::getAddress(hkClassMemberAccessor *this)
{
  return this->m_address;
}

// File Line: 72
// RVA: 0x12FF400
void **__fastcall hkClassMemberAccessor::asPointer(hkClassMemberAccessor *this, int index)
{
  return (void **)((char *)this->m_address + 8 * index);
}

// File Line: 78
// RVA: 0x12FF420
char **__fastcall hkClassMemberAccessor::asCstring(hkClassMemberAccessor *this, int index)
{
  return (char **)((char *)this->m_address + 8 * index);
}

// File Line: 84
// RVA: 0x12FF440
hkStringPtr *__fastcall hkClassMemberAccessor::asStringPtr(hkClassMemberAccessor *this, int index)
{
  return (hkStringPtr *)((char *)this->m_address + 8 * index);
}

// File Line: 90
// RVA: 0x12FF460
hkBool *__fastcall hkClassMemberAccessor::asBool(hkClassMemberAccessor *this, int index)
{
  return (hkBool *)this->m_address + index;
}

// File Line: 96
// RVA: 0x12FF470
float *__fastcall hkClassMemberAccessor::asReal(hkClassMemberAccessor *this, int index)
{
  return (float *)((char *)this->m_address + 4 * index);
}

// File Line: 102
// RVA: 0x12FF490
hkHalf *__fastcall hkClassMemberAccessor::asHalf(hkClassMemberAccessor *this, int index)
{
  return (hkHalf *)((char *)this->m_address + 2 * index);
}

// File Line: 108
// RVA: 0x12FF4B0
int *__fastcall hkClassMemberAccessor::asInt32(hkClassMemberAccessor *this, int index)
{
  return (int *)((char *)this->m_address + 4 * index);
}

// File Line: 114
// RVA: 0x12FF4D0
unsigned int *__fastcall hkClassMemberAccessor::asUint32(hkClassMemberAccessor *this, int index)
{
  return (unsigned int *)((char *)this->m_address + 4 * index);
}

// File Line: 120
// RVA: 0x12FF4F0
__int64 *__fastcall hkClassMemberAccessor::asInt64(hkClassMemberAccessor *this, int index)
{
  return (__int64 *)((char *)this->m_address + 8 * index);
}

// File Line: 126
// RVA: 0x12FF510
unsigned __int64 *__fastcall hkClassMemberAccessor::asUint64(hkClassMemberAccessor *this, int index)
{
  return (unsigned __int64 *)((char *)this->m_address + 8 * index);
}

// File Line: 132
// RVA: 0x12FF530
unsigned __int64 *__fastcall hkClassMemberAccessor::asUlong(hkClassMemberAccessor *this, int index)
{
  return (unsigned __int64 *)((char *)this->m_address + 8 * index);
}

// File Line: 138
// RVA: 0x12FF550
__int16 *__fastcall hkClassMemberAccessor::asInt16(hkClassMemberAccessor *this, int index)
{
  return (__int16 *)((char *)this->m_address + 2 * index);
}

// File Line: 144
// RVA: 0x12FF570
unsigned __int16 *__fastcall hkClassMemberAccessor::asUint16(hkClassMemberAccessor *this, int index)
{
  return (unsigned __int16 *)((char *)this->m_address + 2 * index);
}

// File Line: 150
// RVA: 0x12FF590
char *__fastcall hkClassMemberAccessor::asInt8(hkClassMemberAccessor *this, int index)
{
  return (char *)this->m_address + index;
}

// File Line: 156
// RVA: 0x12FF5A0
char *__fastcall hkClassMemberAccessor::asUint8(hkClassMemberAccessor *this, int index)
{
  return (char *)this->m_address + index;
}

// File Line: 162
// RVA: 0x12FF610
hkClassMemberAccessor::Vector4 *__fastcall hkClassMemberAccessor::asVector4(hkClassMemberAccessor *this, int index)
{
  return (hkClassMemberAccessor::Vector4 *)((char *)this->m_address + 16 * index);
}

// File Line: 168
// RVA: 0x12FF630
hkClassMemberAccessor::Matrix3 *__fastcall hkClassMemberAccessor::asMatrix3(hkClassMemberAccessor *this, int index)
{
  return (hkClassMemberAccessor::Matrix3 *)((char *)this->m_address + 48 * index);
}

// File Line: 174
// RVA: 0x12FF650
hkClassMemberAccessor::Transform *__fastcall hkClassMemberAccessor::asTransform(hkClassMemberAccessor *this, int index)
{
  return (hkClassMemberAccessor::Transform *)((char *)this->m_address + 64 * (signed __int64)index);
}

// File Line: 180
// RVA: 0x12FF670
hkClassMemberAccessor::Matrix3 *__fastcall hkClassMemberAccessor::asRotation(hkClassMemberAccessor *this, int index)
{
  return (hkClassMemberAccessor::Matrix3 *)((char *)this->m_address + 48 * index);
}

// File Line: 186
// RVA: 0x12FF5B0
hkClassMemberAccessor::SimpleArray *__fastcall hkClassMemberAccessor::asSimpleArray(hkClassMemberAccessor *this, int index)
{
  return (hkClassMemberAccessor::SimpleArray *)((char *)this->m_address + 16 * index);
}

// File Line: 192
// RVA: 0x12FF5D0
hkClassMemberAccessor::HomogeneousArray *__fastcall hkClassMemberAccessor::asHomogeneousArray(hkClassMemberAccessor *this, int index)
{
  return (hkClassMemberAccessor::HomogeneousArray *)((char *)this->m_address + 24 * index);
}

// File Line: 198
// RVA: 0x12FF5F0
hkVariant *__fastcall hkClassMemberAccessor::asVariant(hkClassMemberAccessor *this, int index)
{
  return (hkVariant *)((char *)this->m_address + 16 * index);
}

// File Line: 204
// RVA: 0x12FF3D0
hkClassMember *__fastcall hkClassMemberAccessor::getClassMember(hkClassMemberAccessor *this)
{
  return this->m_member;
}

// File Line: 210
// RVA: 0x12FF690
hkClassMemberAccessor *__fastcall hkClassMemberAccessor::member(hkClassMemberAccessor *this, hkClassMemberAccessor *result, const char *name)
{
  hkClassMemberAccessor *v3; // rbx
  const char *v4; // rdi
  hkClassMemberAccessor *v5; // rsi
  hkClass *v6; // rax

  v3 = this;
  v4 = name;
  v5 = result;
  v6 = hkClassMember::getStructClass(this->m_member);
  hkClassMemberAccessor::hkClassMemberAccessor(v5, v3->m_address, v6, v4);
  return v5;
}

// File Line: 219
// RVA: 0x12FF6E0
hkClassAccessor *__fastcall hkClassMemberAccessor::object(hkClassMemberAccessor *this, hkClassAccessor *result)
{
  hkClassMemberAccessor *v2; // rbx
  hkClassAccessor *v3; // rdi
  hkClass *v4; // rax

  v2 = this;
  v3 = result;
  v4 = hkClassMember::getStructClass(this->m_member);
  hkClassAccessor::hkClassAccessor(v3, v2->m_address, v4);
  return v3;
}

// File Line: 226
// RVA: 0x12FF790
void __fastcall hkClassAccessor::hkClassAccessor(hkClassAccessor *this, void *object, hkClass *klass)
{
  this->m_variant.m_object = object;
  this->m_variant.m_class = klass;
}

// File Line: 235
// RVA: 0x12FF7B0
void __fastcall hkClassAccessor::hkClassAccessor(hkClassAccessor *this, hkVariant *v)
{
  *this = (hkClassAccessor)*v;
}

