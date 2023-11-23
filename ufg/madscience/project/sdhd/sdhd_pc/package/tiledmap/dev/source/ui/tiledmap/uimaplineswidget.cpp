// File Line: 25
// RVA: 0xBCE60
void __fastcall UFG::UIMapLinesWidget::UIMapLinesWidget(UFG::UIMapLinesWidget *this)
{
  *(_WORD *)&this->mClipToPlayerPos = 256;
  this->mVisible = 0;
  *(_QWORD *)&this->mPlayerPos.x = 0i64;
  *(_QWORD *)&this->mPlayerPos.z = 0i64;
  this->mLineData.p = 0i64;
  this->mLineData.capacity = 0;
  this->mActiveLines.p = 0i64;
  *(_QWORD *)&this->mActiveLines.size = 0i64;
}

// File Line: 30
// RVA: 0xCC610
void __fastcall UFG::UIMapLinesWidget::Update(UFG::UIMapLinesWidget *this, float elapsed, UFG::UITiledMapMath *geo)
{
  float x; // xmm2_4
  float y; // xmm3_4
  __m128 y_low; // xmm0
  float z; // xmm0_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 dir; // [rsp+30h] [rbp-18h] BYREF

  if ( this->mClipToPlayerPos )
  {
    if ( UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
    {
      x = pos.x;
      y = pos.y;
      y_low = (__m128)LODWORD(pos.y);
      y_low.m128_f32[0] = (float)((float)(pos.y - this->mPlayerPos.y) * (float)(pos.y - this->mPlayerPos.y))
                        + (float)((float)(pos.x - this->mPlayerPos.x) * (float)(pos.x - this->mPlayerPos.x));
      if ( _mm_sqrt_ps(y_low).m128_f32[0] > 5.0 )
      {
        z = pos.z;
        this->mChanged = 1;
        this->mPlayerPos.x = x;
        this->mPlayerPos.z = z;
        this->mPlayerPos.y = y;
      }
    }
  }
  if ( this->mChanged )
  {
    UFG::UIMapLinesWidget::Refresh(this);
    this->mChanged = 0;
  }
}

// File Line: 51
// RVA: 0xC4D60
void __fastcall UFG::UIMapLinesWidget::HandleScreenInit(UFG::UIMapLinesWidget *this)
{
  this->mChanged = 1;
}

// File Line: 57
// RVA: 0xCB8C0
void __fastcall UFG::UIMapLinesWidget::SetVisible(UFG::UIMapLinesWidget *this, bool visible)
{
  bool v2; // zf

  v2 = this->mVisible == visible;
  this->mVisible = visible;
  this->mChanged |= !v2;
}

// File Line: 64
// RVA: 0xBE1B0
void __fastcall UFG::UIMapLinesWidget::Add(UFG::UIMapLinesWidget *this, UFG::UIHKMapLine *line)
{
  UFG::qArray<UFG::UIHKMapLine,0>::Add(&this->mLineData, line, "qArray.Add");
  this->mChanged = 1;
}

// File Line: 71
// RVA: 0xBE950
void __fastcall UFG::UIMapLinesWidget::Clear(UFG::UIMapLinesWidget *this)
{
  UFG::UIHKMapLine *p; // rcx

  p = this->mLineData.p;
  if ( p )
    operator delete[](p);
  this->mLineData.p = 0i64;
  *(_QWORD *)&this->mLineData.size = 0i64;
  this->mChanged = 1;
}

// File Line: 78
// RVA: 0xC6DC0
void __fastcall UFG::UIMapLinesWidget::Refresh(UFG::UIMapLinesWidget *this)
{
  unsigned int v1; // ebp
  float y; // xmm7_4
  float x; // xmm8_4
  unsigned int ClosestLineIndex; // eax
  UFG::UIHKMapLine *v6; // rax
  UFG::UIHKMapLine *v7; // rbx
  float v8; // xmm5_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  UFG::UIHKMapLine *v11; // rdx
  float v12; // xmm6_4
  float v13; // xmm7_4
  __int64 size; // rdi
  unsigned int capacity; // edx
  unsigned int v16; // ebx
  unsigned int v17; // edx
  UFG::UIHKMapLine *v18; // rax
  __int64 v19; // r15
  unsigned int v20; // edx
  unsigned int v21; // ebx
  UFG::UIHKMapLine *v22; // rdi
  unsigned int v23; // edx
  float v24; // eax
  UFG::UIHKMapLine *v25; // rcx
  float v26; // xmm0_4
  UFG::qVector2 P; // [rsp+90h] [rbp+8h] BYREF
  UFG::qVector2 closest_point; // [rsp+98h] [rbp+10h] BYREF

  v1 = 0;
  this->mActiveLines.size = 0;
  if ( !this->mLineData.size )
    return;
  if ( this->mClipToPlayerPos )
  {
    y = this->mPlayerPos.y;
    P.y = y;
    x = this->mPlayerPos.x;
    P.x = x;
    ClosestLineIndex = UFG::UIMapLinesWidget::GetClosestLineIndex(this, &P);
    v1 = ClosestLineIndex;
    if ( ClosestLineIndex )
    {
      v6 = &this->mLineData.p[ClosestLineIndex - 1];
      v7 = &this->mLineData.p[v1];
      v8 = v6->start.x;
      if ( (float)((float)((float)((float)(y - v6->start.y) * (float)(y - v6->start.y))
                         + (float)((float)(x - v8) * (float)(x - v8)))
                 / (float)((float)((float)(v6->start.y - v6->end.y) * (float)(v6->start.y - v6->end.y))
                         + (float)((float)(v8 - v6->end.x) * (float)(v8 - v6->end.x)))) < (float)((float)((float)((float)(y - v7->end.y) * (float)(y - v7->end.y)) + (float)((float)(x - v7->end.x) * (float)(x - v7->end.x)))
                                                                                                / (float)((float)((float)(v7->start.y - v7->end.y) * (float)(v7->start.y - v7->end.y)) + (float)((float)(v7->start.x - v7->end.x) * (float)(v7->start.x - v7->end.x)))) )
      {
        UFG::qGetClosestPointOnSegment(
          &closest_point,
          &this->mLineData.p[v1 - 1].start,
          &this->mLineData.p[v1].start,
          &P);
        v9 = v7->start.x;
        v10 = v7->start.y;
LABEL_9:
        v12 = closest_point.x;
        v13 = closest_point.y;
        if ( v9 != closest_point.x || v10 != closest_point.y )
        {
          size = this->mActiveLines.size;
          capacity = this->mActiveLines.capacity;
          v16 = size + 1;
          if ( (int)size + 1 > capacity )
          {
            if ( capacity )
              v17 = 2 * capacity;
            else
              v17 = 1;
            for ( ; v17 < v16; v17 *= 2 )
              ;
            if ( v17 - v16 > 0x10000 )
              v17 = size + 65537;
            UFG::qArray<UFG::UIHKMapLine,0>::Reallocate(&this->mActiveLines, v17, "qArray.Add");
          }
          this->mActiveLines.size = v16;
          v18 = &this->mActiveLines.p[size];
          v18->start.x = v12;
          v18->start.y = v13;
          v18->end.x = v9;
          v18->end.y = v10;
        }
        goto LABEL_21;
      }
      UFG::qGetClosestPointOnSegment(&closest_point, &this->mLineData.p[v1].start, &v7->end, &P);
      v9 = v7->end.x;
      v10 = v7->end.y;
    }
    else
    {
      v11 = this->mLineData.p;
      v9 = v11->start.x;
      v10 = v11->start.y;
      UFG::qGetClosestPointOnSegment(&closest_point, &v11->start, &v11->end, &P);
    }
    ++v1;
    goto LABEL_9;
  }
LABEL_21:
  while ( v1 < this->mLineData.size )
  {
    v19 = this->mActiveLines.size;
    v20 = this->mActiveLines.capacity;
    v21 = v19 + 1;
    v22 = &this->mLineData.p[v1];
    if ( (int)v19 + 1 > v20 )
    {
      if ( v20 )
        v23 = 2 * v20;
      else
        v23 = 1;
      for ( ; v23 < v21; v23 *= 2 )
        ;
      if ( v23 - v21 > 0x10000 )
        v23 = v19 + 65537;
      UFG::qArray<UFG::UIHKMapLine,0>::Reallocate(&this->mActiveLines, v23, "qArray.Add");
    }
    this->mActiveLines.size = v21;
    v24 = v22->start.x;
    ++v1;
    v25 = &this->mActiveLines.p[v19];
    v25->start.y = v22->start.y;
    v25->start.x = v24;
    v26 = v22->end.y;
    v25->end.x = v22->end.x;
    v25->end.y = v26;
  }
}

// File Line: 146
// RVA: 0xC0D90
__int64 __fastcall UFG::UIMapLinesWidget::GetClosestLineIndex(UFG::UIMapLinesWidget *this, UFG::qVector2 *pos)
{
  unsigned int size; // r11d
  float v3; // xmm2_4
  unsigned int v4; // r9d
  unsigned int v7; // r8d
  __int64 v8; // rax
  UFG::UIHKMapLine *p; // rax
  float x; // xmm3_4
  float y; // xmm4_4
  int v12; // ecx
  float *p_start; // rdx
  float *p_y; // r10
  float v15; // xmm4_4
  UFG::UIHKMapLine *v16; // rax

  size = this->mLineData.size;
  v3 = FLOAT_9999999_0;
  v4 = 0;
  v7 = 0;
  v8 = 0i64;
  if ( (int)size >= 4 )
  {
    p = this->mLineData.p;
    x = pos->x;
    y = pos->y;
    v12 = 2;
    p_start = (float *)&p[1].start;
    p_y = &p[2].start.y;
    v8 = 4i64 * (((size - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)(y - *(p_start - 3)) * (float)(y - *(p_start - 3)))
                 + (float)((float)(x - *(p_start - 4)) * (float)(x - *(p_start - 4)))) < v3 )
      {
        v3 = (float)((float)(y - *(p_start - 3)) * (float)(y - *(p_start - 3)))
           + (float)((float)(x - *(p_start - 4)) * (float)(x - *(p_start - 4)));
        v4 = v7;
      }
      if ( (float)((float)((float)(y - *(p_y - 4)) * (float)(y - *(p_y - 4)))
                 + (float)((float)(x - *p_start) * (float)(x - *p_start))) < v3 )
      {
        v3 = (float)((float)(y - *(p_y - 4)) * (float)(y - *(p_y - 4)))
           + (float)((float)(x - *p_start) * (float)(x - *p_start));
        v4 = v12 - 1;
      }
      if ( (float)((float)((float)(y - *p_y) * (float)(y - *p_y))
                 + (float)((float)(x - p_start[4]) * (float)(x - p_start[4]))) < v3 )
      {
        v3 = (float)((float)(y - *p_y) * (float)(y - *p_y)) + (float)((float)(x - p_start[4]) * (float)(x - p_start[4]));
        v4 = v12;
      }
      if ( (float)((float)((float)(y - p_y[4]) * (float)(y - p_y[4]))
                 + (float)((float)(x - p_start[8]) * (float)(x - p_start[8]))) < v3 )
      {
        v3 = (float)((float)(y - p_y[4]) * (float)(y - p_y[4]))
           + (float)((float)(x - p_start[8]) * (float)(x - p_start[8]));
        v4 = v12 + 1;
      }
      v7 += 4;
      p_start += 16;
      p_y += 16;
      v12 += 4;
    }
    while ( v7 < size - 3 );
  }
  if ( v7 < size )
  {
    v16 = &this->mLineData.p[v8];
    do
    {
      v15 = pos->y;
      if ( (float)((float)((float)(v15 - v16->start.y) * (float)(v15 - v16->start.y))
                 + (float)((float)(pos->x - v16->start.x) * (float)(pos->x - v16->start.x))) < v3 )
      {
        v3 = (float)((float)(v15 - v16->start.y) * (float)(v15 - v16->start.y))
           + (float)((float)(pos->x - v16->start.x) * (float)(pos->x - v16->start.x));
        v4 = v7;
      }
      ++v7;
      ++v16;
    }
    while ( v7 < size );
  }
  return v4;
}

