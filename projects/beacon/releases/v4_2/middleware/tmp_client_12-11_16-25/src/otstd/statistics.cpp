// File Line: 7
// RVA: 0xEEB044
void __fastcall OSuite::Statistics::Statistics(OSuite::Statistics *this, int movingAverageSize)
{
  this->maSize = movingAverageSize;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::Statistics::`vftable;
  this->maData = (float *)OSuite::ZObject::m_allocator->vfptr->malloc(
                            OSuite::ZObject::m_allocator,
                            4i64 * movingAverageSize,
                            0i64);
  OSuite::Statistics::Reset(this);
}

// File Line: 15
// RVA: 0xEEB088
void __fastcall OSuite::Statistics::~Statistics(OSuite::Statistics *this)
{
  float *maData; // rdx

  maData = this->maData;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::Statistics::`vftable;
  OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, maData);
  this->maData = 0i64;
}

// File Line: 21
// RVA: 0xEEB184
void __fastcall OSuite::Statistics::Reset(OSuite::Statistics *this)
{
  int v1; // edx
  __int64 v2; // r8

  v1 = 0;
  if ( this->maSize > 0 )
  {
    v2 = 0i64;
    do
    {
      ++v1;
      this->maData[v2++] = 0.0;
    }
    while ( v1 < this->maSize );
  }
  this->count = 0;
  *(_QWORD *)&this->previous = 0i64;
  *(_QWORD *)&this->min = 0i64;
  this->max = 0.0;
}

// File Line: 29
// RVA: 0xEEB0E8
void __fastcall OSuite::Statistics::AddDeltaValue(OSuite::Statistics *this, float value)
{
  float *maData; // rax
  __int64 v4; // r8
  bool v5; // cc
  float v6; // xmm0_4
  float v7; // xmm1_4

  maData = this->maData;
  v4 = this->count % this->maSize;
  this->maTotal = this->maTotal - maData[v4];
  maData[v4] = value;
  v5 = value <= this->max;
  v6 = value + this->total;
  v7 = value + this->maTotal;
  this->total = v6;
  this->maTotal = v7;
  if ( !v5 || !this->count )
    this->max = value;
  if ( this->min > value || !this->count )
    this->min = value;
  ++this->count;
}

// File Line: 44
// RVA: 0xEEB150
// attributes: thunk
void __fastcall OSuite::Statistics::AddValue(OSuite::Statistics *this, float value)
{
  OSuite::Statistics::AddDeltaValue(this, value);
}

// File Line: 69
// RVA: 0xEEB158
float __fastcall OSuite::Statistics::GetAverage(OSuite::Statistics *this)
{
  if ( this->count )
    return this->total / (float)this->count;
  else
    return 0.0;
}

// File Line: 82
// RVA: 0xEEB174
float __fastcall OSuite::Statistics::GetMax(OSuite::Statistics *this)
{
  return this->max;
}

// File Line: 87
// RVA: 0xEEB17C
float __fastcall OSuite::Statistics::GetMin(OSuite::Statistics *this)
{
  return this->min;
}

