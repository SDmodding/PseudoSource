// File Line: 53
// RVA: 0x1453290
void dynamic_initializer_for__UFG::DrawInfo::msDefault__()
{
  LODWORD(UFG::DrawInfo::msDefault.mColour1.r) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour1.g) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour1.b) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour1.a) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour2.r) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour2.g) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour2.b) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour2.a) = (_DWORD)FLOAT_1_0;
}

// File Line: 180
// RVA: 0x170B0
void __fastcall Render::DebugLineStrip::DebugLineStrip(
        Render::DebugLineStrip *this,
        UFG::qLinearAllocator *pool,
        UFG::qVector3 *p0,
        UFG::qVector3 *p1,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *),
        bool is_screen_coords)
{
  char *v11; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 *m_Points; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4

  this->mPrev = this;
  this->mNext = this;
  this->m_LocalWorld = local_world;
  this->m_NumPoints = 2;
  this->m_DrawInfo.mColour1.r = UFG::DrawInfo::msDefault.mColour1.r;
  this->m_DrawInfo.mColour1.g = UFG::DrawInfo::msDefault.mColour1.g;
  this->m_DrawInfo.mColour1.b = UFG::DrawInfo::msDefault.mColour1.b;
  this->m_DrawInfo.mColour1.a = UFG::DrawInfo::msDefault.mColour1.a;
  this->m_DrawInfo.mColour2 = UFG::DrawInfo::msDefault.mColour2;
  this->m_DrawInfo.mScale = UFG::DrawInfo::msDefault.mScale;
  this->m_DrawInfo.mAlphaBlend = UFG::DrawInfo::msDefault.mAlphaBlend;
  this->m_DrawInfo.mDepthBuffer = UFG::DrawInfo::msDefault.mDepthBuffer;
  this->m_DrawInfo.mFaceCull = UFG::DrawInfo::msDefault.mFaceCull;
  this->m_DrawInfo.mDepthBias = UFG::DrawInfo::msDefault.mDepthBias;
  this->m_DrawInfo.mPreDrawCallback = UFG::DrawInfo::msDefault.mPreDrawCallback;
  this->m_DrawInfo.mColour1 = *colour;
  this->m_DrawInfo.mColour2 = *colour;
  this->m_DrawInfo.mPreDrawCallback = pre_draw_callback;
  v11 = UFG::qLinearAllocator::Malloc(pool, 12 * this->m_NumPoints, 4u);
  this->m_Points = (UFG::qVector3 *)v11;
  if ( v11 )
  {
    y = p0->y;
    z = p0->z;
    *(float *)v11 = p0->x;
    *((float *)v11 + 1) = y;
    *((float *)v11 + 2) = z;
    m_Points = this->m_Points;
    v15 = p1->y;
    v16 = p1->z;
    m_Points[1].x = p1->x;
    m_Points[1].y = v15;
    m_Points[1].z = v16;
  }
  this->m_NumPoints |= is_screen_coords ? 0x10000 : 0;
}

// File Line: 197
// RVA: 0x17260
void __fastcall Render::DebugLineStrip::DebugLineStrip(
        Render::DebugLineStrip *this,
        UFG::qLinearAllocator *pool,
        UFG::qVector3 *points,
        int num_points,
        UFG::DrawInfo *info,
        UFG::qMatrix44 *local_world)
{
  char *v9; // rax

  this->mPrev = this;
  this->mNext = this;
  this->m_LocalWorld = local_world;
  this->m_NumPoints = num_points;
  this->m_DrawInfo.mColour1.r = info->mColour1.r;
  this->m_DrawInfo.mColour1.g = info->mColour1.g;
  this->m_DrawInfo.mColour1.b = info->mColour1.b;
  this->m_DrawInfo.mColour1.a = info->mColour1.a;
  this->m_DrawInfo.mColour2 = info->mColour2;
  this->m_DrawInfo.mScale = info->mScale;
  this->m_DrawInfo.mAlphaBlend = info->mAlphaBlend;
  this->m_DrawInfo.mDepthBuffer = info->mDepthBuffer;
  this->m_DrawInfo.mFaceCull = info->mFaceCull;
  this->m_DrawInfo.mDepthBias = info->mDepthBias;
  this->m_DrawInfo.mPreDrawCallback = info->mPreDrawCallback;
  v9 = UFG::qLinearAllocator::Malloc(pool, 12 * this->m_NumPoints, 4u);
  this->m_Points = (UFG::qVector3 *)v9;
  if ( v9 )
    UFG::qMemCopy(v9, points, 12 * num_points);
}

// File Line: 227
// RVA: 0x17350
void __fastcall Render::DebugTriStrip::DebugTriStrip(
        Render::DebugTriStrip *this,
        UFG::qLinearAllocator *pool,
        UFG::qVector3 *points,
        int num_points,
        UFG::DrawInfo *info,
        UFG::qMatrix44 *local_world,
        bool is_screen_coords)
{
  char *v10; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mNumPoints = num_points;
  this->mDrawInfo.mColour1.r = info->mColour1.r;
  this->mDrawInfo.mColour1.g = info->mColour1.g;
  this->mDrawInfo.mColour1.b = info->mColour1.b;
  this->mDrawInfo.mColour1.a = info->mColour1.a;
  this->mDrawInfo.mColour2 = info->mColour2;
  this->mDrawInfo.mScale = info->mScale;
  this->mDrawInfo.mAlphaBlend = info->mAlphaBlend;
  this->mDrawInfo.mDepthBuffer = info->mDepthBuffer;
  this->mDrawInfo.mFaceCull = info->mFaceCull;
  this->mDrawInfo.mDepthBias = info->mDepthBias;
  this->mDrawInfo.mPreDrawCallback = info->mPreDrawCallback;
  this->mLocalWorld = local_world;
  this->mPoints = 0i64;
  this->mSortMetric = 0.0;
  this->mInFront = info->mDepthBias;
  v10 = UFG::qLinearAllocator::Malloc(pool, 12 * this->mNumPoints, 4u);
  this->mPoints = (UFG::qVector3 *)v10;
  if ( v10 )
    UFG::qMemCopy(v10, points, 12 * num_points);
  this->mNumPoints |= is_screen_coords ? 0x10000 : 0;
}

// File Line: 248
// RVA: 0x16D40
void __fastcall Render::DebugAABB::DebugAABB(
        Render::DebugAABB *this,
        UFG::qVector3 *min,
        UFG::qVector3 *max,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  this->mPrev = this;
  this->mNext = this;
  y = min->y;
  z = min->z;
  this->m_Min.x = min->x;
  this->m_Min.y = y;
  this->m_Min.z = z;
  v8 = max->y;
  v9 = max->z;
  this->m_Max.x = max->x;
  this->m_Max.y = v8;
  this->m_Max.z = v9;
  this->m_Colour = *colour;
  this->m_LocalWorld = local_world;
  this->m_PreDrawCallback = pre_draw_callback;
}

// File Line: 296
// RVA: 0x16E70
void __fastcall Render::DebugCylinder::DebugCylinder(
        Render::DebugCylinder *this,
        UFG::qVector3 *min,
        UFG::qVector3 *max,
        float radius,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  this->mPrev = this;
  this->mNext = this;
  y = min->y;
  z = min->z;
  this->m_Min.x = min->x;
  this->m_Min.y = y;
  this->m_Min.z = z;
  v9 = max->y;
  v10 = max->z;
  this->m_Max.x = max->x;
  this->m_Max.y = v9;
  this->m_Max.z = v10;
  this->m_Radius = radius;
  this->m_Colour = *colour;
  this->m_LocalWorld = local_world;
  this->m_PreDrawCallback = pre_draw_callback;
}

// File Line: 321
// RVA: 0x16DD0
void __fastcall Render::DebugCircle::DebugCircle(
        Render::DebugCircle *this,
        UFG::qVector3 *centre,
        UFG::qVector3 *normal,
        float radius,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  this->mPrev = this;
  this->mNext = this;
  y = centre->y;
  z = centre->z;
  this->m_Centre.x = centre->x;
  this->m_Centre.y = y;
  this->m_Centre.z = z;
  v9 = normal->y;
  v10 = normal->z;
  this->m_Normal.x = normal->x;
  this->m_Normal.y = v9;
  this->m_Normal.z = v10;
  this->m_Radius = radius;
  this->m_Colour = *colour;
  this->m_LocalWorld = local_world;
  this->m_PreDrawCallback = pre_draw_callback;
}

// File Line: 417
// RVA: 0x16F10
void __fastcall Render::DebugData::DebugData(Render::DebugData *this, unsigned int debug_pool_size)
{
  char *v4; // rax
  unsigned int v5; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax

  UFG::qResourceHandle::qResourceHandle(&this->mDebugFontHandle);
  this->mDebugTextLines.mNode.mPrev = &this->mDebugTextLines.mNode;
  this->mDebugTextLines.mNode.mNext = &this->mDebugTextLines.mNode;
  this->mDebugRects.mNode.mPrev = &this->mDebugRects.mNode;
  this->mDebugRects.mNode.mNext = &this->mDebugRects.mNode;
  this->mDebugIcons.mNode.mPrev = &this->mDebugIcons.mNode;
  this->mDebugIcons.mNode.mNext = &this->mDebugIcons.mNode;
  this->mDebugLineStrips.mNode.mPrev = &this->mDebugLineStrips.mNode;
  this->mDebugLineStrips.mNode.mNext = &this->mDebugLineStrips.mNode;
  this->mDebugTriStrips.mNode.mPrev = &this->mDebugTriStrips.mNode;
  this->mDebugTriStrips.mNode.mNext = &this->mDebugTriStrips.mNode;
  this->mDebugAABB.mNode.mPrev = &this->mDebugAABB.mNode;
  this->mDebugAABB.mNode.mNext = &this->mDebugAABB.mNode;
  this->mDebugSphere.mNode.mPrev = &this->mDebugSphere.mNode;
  this->mDebugSphere.mNode.mNext = &this->mDebugSphere.mNode;
  this->mDebugCylinder.mNode.mPrev = &this->mDebugCylinder.mNode;
  this->mDebugCylinder.mNode.mNext = &this->mDebugCylinder.mNode;
  this->mDebugCircle.mNode.mPrev = &this->mDebugCircle.mNode;
  this->mDebugCircle.mNode.mNext = &this->mDebugCircle.mNode;
  this->mDebugArc.mNode.mPrev = &this->mDebugArc.mNode;
  this->mDebugArc.mNode.mNext = &this->mDebugArc.mNode;
  this->mDebugAxis.mNode.mPrev = &this->mDebugAxis.mNode;
  this->mDebugAxis.mNode.mNext = &this->mDebugAxis.mNode;
  UFG::qLinearAllocator::qLinearAllocator(&this->mDebugMemory);
  this->mDebugPoolSize = debug_pool_size;
  v4 = UFG::qMalloc(debug_pool_size, "DebugData::mDebugPool", 0i64);
  this->mDebugPool = v4;
  UFG::qLinearAllocator::Init(&this->mDebugMemory, v4, this->mDebugPoolSize, 0i64, 0i64);
  this->mHaveExceededPool = 0;
  v5 = UFG::qStringHash32("LucidaConsole", 0xFFFFFFFF);
  Inventory = `UFG::qGetResourceInventory<Render::Font>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::Font>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x69FCCB4Cu);
    `UFG::qGetResourceInventory<Render::Font>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mDebugFontHandle, 0x69FCCB4Cu, v5, Inventory);
}

// File Line: 432
// RVA: 0x17790
UFG::qMatrix44 *__fastcall Render::DebugData::AllocMatrix(Render::DebugData *this, UFG::qMatrix44 *matrix)
{
  UFG::qMatrix44 *result; // rax
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  if ( !matrix )
    return 0i64;
  result = (UFG::qMatrix44 *)UFG::qLinearAllocator::Malloc(&this->mDebugMemory, 0x40u, 0x10u);
  if ( !result )
    return 0i64;
  v4 = matrix->v1;
  v5 = matrix->v2;
  v6 = matrix->v3;
  result->v0 = matrix->v0;
  result->v1 = v4;
  result->v2 = v5;
  result->v3 = v6;
  return result;
}

// File Line: 502
// RVA: 0x18EB0
void Render::DebugDrawContext::DrawTextA(
        Render::DebugDrawContext *this,
        int x,
        int y,
        UFG::qColour *colour,
        const char *format,
        ...)
{
  Render::DebugData *fontName; // r10
  va_list va; // [rsp+78h] [rbp+30h] BYREF

  va_start(va, format);
  fontName = this->mDebugData;
  if ( fontName )
  {
    if ( !gDisableDebugDraw )
      Render::DebugDrawContext::DrawTextArgs(
        this,
        x,
        y,
        9u,
        (int)format,
        &fontName->mDebugFontHandle,
        colour,
        format,
        va);
  }
}

// File Line: 532
// RVA: 0x18E60
void Render::DebugDrawContext::DrawText(
        Render::DebugDrawContext *this,
        UFG::qVector3 *world_position,
        UFG::qColour *colour,
        const char *format,
        ...)
{
  Render::DebugData *mDebugData; // rax
  va_list va; // [rsp+70h] [rbp+28h] BYREF

  va_start(va, format);
  mDebugData = this->mDebugData;
  if ( mDebugData )
  {
    if ( !gDisableDebugDraw )
      Render::DebugDrawContext::DrawTextArgs(
        this,
        world_position,
        9u,
        &mDebugData->mDebugFontHandle,
        (int)mDebugData,
        colour,
        format,
        va);
  }
}

// File Line: 572
// RVA: 0x18F40
void Render::DebugDrawContext::DrawTextAligned(
        Render::DebugDrawContext *this,
        int x,
        int y,
        unsigned int align_flags,
        Render::FontHandle *fontName,
        UFG::qColour *colour,
        const char *format,
        ...)
{
  va_list va; // [rsp+88h] [rbp+40h] BYREF

  va_start(va, format);
  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
      Render::DebugDrawContext::DrawTextArgs(this, x, y, align_flags, (int)fontName, fontName, colour, format, va);
  }
}

// File Line: 594
// RVA: 0x18F00
void Render::DebugDrawContext::DrawTextAligned(
        Render::DebugDrawContext *this,
        UFG::qVector3 *world_position,
        unsigned int align_flags,
        Render::FontHandle *fontName,
        UFG::qColour *colour,
        const char *format,
        ...)
{
  va_list va; // [rsp+80h] [rbp+38h] BYREF

  va_start(va, format);
  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
      Render::DebugDrawContext::DrawTextArgs(
        this,
        world_position,
        align_flags,
        fontName,
        (int)colour,
        colour,
        format,
        va);
  }
}

// File Line: 607
// RVA: 0x19110
void __fastcall Render::DebugDrawContext::DrawTextArgs(
        Render::DebugDrawContext *this,
        int x,
        int y,
        unsigned int alignment,
        Render::FontHandle *fontName,
        UFG::qColour *colour,
        char *format,
        char *args)
{
  int v8; // eax
  int v13; // eax
  int v14; // esi
  char *v15; // rax
  char *v16; // rdi
  char *v17; // rax
  char *v18; // rdx
  __int128 v19; // xmm0
  UFG::qList<Render::DebugText,Render::DebugText,1,0> *p_mDebugTextLines; // rcx
  UFG::qNode<Render::DebugText,Render::DebugText> *mPrev; // rax
  char dest[8192]; // [rsp+30h] [rbp-2018h] BYREF

  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      v13 = UFG::qVSPrintf(dest, v8 - 48, format, args);
      if ( v13 )
      {
        v14 = v13 + 1;
        v15 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, v13 + 1, 1u);
        v16 = v15;
        if ( v15
          && (UFG::qStringCopy(v15, v14, dest, -1),
              v17 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x48u, 0x10u),
              (v18 = v17) != 0i64) )
        {
          v19 = (__int128)*colour;
          *(_QWORD *)v17 = v17;
          *((_QWORD *)v17 + 1) = v17;
          *((_QWORD *)v17 + 3) = fontName;
          *((_DWORD *)v17 + 13) = alignment;
          *((_QWORD *)v17 + 2) = v16;
          *((_OWORD *)v17 + 2) = v19;
          *((float *)v17 + 14) = (float)x;
          *((float *)v17 + 15) = (float)y;
          *((_DWORD *)v17 + 12) = 0;
          p_mDebugTextLines = &this->mDebugData->mDebugTextLines;
          mPrev = p_mDebugTextLines->mNode.mPrev;
          mPrev->mNext = (UFG::qNode<Render::DebugText,Render::DebugText> *)v18;
          *(_QWORD *)v18 = mPrev;
          *((_QWORD *)v18 + 1) = p_mDebugTextLines;
          p_mDebugTextLines->mNode.mPrev = (UFG::qNode<Render::DebugText,Render::DebugText> *)v18;
        }
        else
        {
          this->mDebugData->mHaveExceededPool = 1;
        }
      }
    }
  }
}

// File Line: 641
// RVA: 0x18F90
void __fastcall Render::DebugDrawContext::DrawTextArgs(
        Render::DebugDrawContext *this,
        UFG::qVector3 *world_position,
        unsigned int alignment,
        Render::FontHandle *fontName,
        UFG::qColour *colour,
        char *format,
        char *args)
{
  int v7; // eax
  int v12; // eax
  int v13; // esi
  char *v14; // rax
  char *v15; // rdi
  char *v16; // rax
  char *v17; // rdx
  __int128 v18; // xmm0
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  UFG::qList<Render::DebugText,Render::DebugText,1,0> *p_mDebugTextLines; // rcx
  UFG::qNode<Render::DebugText,Render::DebugText> *mPrev; // rax
  char dest[8192]; // [rsp+30h] [rbp-2018h] BYREF

  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      v12 = UFG::qVSPrintf(dest, v7 - 48, format, args);
      if ( v12 )
      {
        v13 = v12 + 1;
        v14 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, v12 + 1, 1u);
        v15 = v14;
        if ( v14
          && (UFG::qStringCopy(v14, v13, dest, -1),
              v16 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x48u, 0x10u),
              (v17 = v16) != 0i64) )
        {
          v18 = (__int128)*colour;
          x = world_position->x;
          y = world_position->y;
          z = world_position->z;
          *(_QWORD *)v16 = v16;
          *((_QWORD *)v16 + 1) = v16;
          *((_QWORD *)v16 + 3) = fontName;
          *((_QWORD *)v16 + 2) = v15;
          *((_OWORD *)v16 + 2) = v18;
          *((float *)v16 + 14) = x;
          *((float *)v16 + 15) = y;
          *((float *)v16 + 16) = z;
          *((_DWORD *)v16 + 12) = 1;
          *((_DWORD *)v16 + 13) = alignment;
          p_mDebugTextLines = &this->mDebugData->mDebugTextLines;
          mPrev = p_mDebugTextLines->mNode.mPrev;
          mPrev->mNext = (UFG::qNode<Render::DebugText,Render::DebugText> *)v17;
          *(_QWORD *)v17 = mPrev;
          *((_QWORD *)v17 + 1) = p_mDebugTextLines;
          p_mDebugTextLines->mNode.mPrev = (UFG::qNode<Render::DebugText,Render::DebugText> *)v17;
        }
        else
        {
          this->mDebugData->mHaveExceededPool = 1;
        }
      }
    }
  }
}

// File Line: 697
// RVA: 0x18C10
void __fastcall Render::DebugDrawContext::DrawRect(
        Render::DebugDrawContext *this,
        float x,
        float y,
        float w,
        float h,
        UFG::qColour *colour)
{
  Render::DebugData *mDebugData; // rcx
  char *v8; // rax
  char *v9; // rdx
  UFG::qList<Render::DebugRect,Render::DebugRect,1,0> *p_mDebugRects; // rcx
  UFG::qNode<Render::DebugRect,Render::DebugRect> *mPrev; // rax

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    v8 = UFG::qLinearAllocator::Malloc(&mDebugData->mDebugMemory, 0x30u, 0x10u);
    v9 = v8;
    if ( v8 )
    {
      *(_QWORD *)v8 = v8;
      *((_QWORD *)v8 + 1) = v8;
      *((float *)v8 + 4) = x;
      *((float *)v8 + 5) = y;
      *((float *)v8 + 6) = w;
      *((float *)v8 + 7) = h;
      *((UFG::qColour *)v8 + 2) = *colour;
      p_mDebugRects = &this->mDebugData->mDebugRects;
      mPrev = p_mDebugRects->mNode.mPrev;
      mPrev->mNext = (UFG::qNode<Render::DebugRect,Render::DebugRect> *)v9;
      *(_QWORD *)v9 = mPrev;
      *((_QWORD *)v9 + 1) = p_mDebugRects;
      p_mDebugRects->mNode.mPrev = (UFG::qNode<Render::DebugRect,Render::DebugRect> *)v9;
    }
    else
    {
      this->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 716
// RVA: 0x18640
void __fastcall Render::DebugDrawContext::DrawLine(
        Render::DebugDrawContext *this,
        UFG::qVector3 *p0,
        UFG::qVector3 *p1,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *),
        bool is_screen_coords)
{
  Render::DebugData *mDebugData; // rcx
  UFG::qMatrix44 *v12; // rdi
  char *v13; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v14; // rax
  UFG::qList<Render::DebugLineStrip,Render::DebugLineStrip,1,0> *p_mDebugLineStrips; // rdx
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *mPrev; // rcx

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    v12 = 0i64;
    if ( (!local_world || (v12 = Render::DebugData::AllocMatrix(mDebugData, local_world)) != 0i64)
      && (v13 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x60u, 0x10u)) != 0i64
      && (Render::DebugLineStrip::DebugLineStrip(
            (Render::DebugLineStrip *)v13,
            &this->mDebugData->mDebugMemory,
            p0,
            p1,
            colour,
            v12,
            pre_draw_callback,
            is_screen_coords),
          v14)
      && v14[1].mPrev )
    {
      p_mDebugLineStrips = &this->mDebugData->mDebugLineStrips;
      mPrev = p_mDebugLineStrips->mNode.mPrev;
      mPrev->mNext = v14;
      v14->mPrev = mPrev;
      v14->mNext = &p_mDebugLineStrips->mNode;
      p_mDebugLineStrips->mNode.mPrev = v14;
    }
    else
    {
      this->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 749
// RVA: 0x17E70
void __fastcall Render::DebugDrawContext::DrawArrow(
        Render::DebugDrawContext *this,
        UFG::qVector3 *p0,
        UFG::qVector3 *p1,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float y; // xmm4_4
  float z; // xmm5_4
  float v8; // xmm13_4
  float x; // xmm12_4
  float v10; // xmm14_4
  __m128 v11; // xmm10
  float v12; // xmm11_4
  __m128 v13; // xmm1
  float v14; // xmm10_4
  float v15; // xmm6_4
  float v16; // xmm8_4
  int v17; // xmm9_4
  float v18; // xmm1_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  UFG::qVector3 line_points; // [rsp+30h] [rbp-E8h] BYREF
  float v25; // [rsp+3Ch] [rbp-DCh]
  int v26; // [rsp+40h] [rbp-D8h]
  float v27; // [rsp+44h] [rbp-D4h]
  float v28; // [rsp+48h] [rbp-D0h]
  float v29; // [rsp+4Ch] [rbp-CCh]
  float v30; // [rsp+50h] [rbp-C8h]
  float v31; // [rsp+54h] [rbp-C4h]
  float v32; // [rsp+58h] [rbp-C0h]
  float v33; // [rsp+5Ch] [rbp-BCh]
  float v34; // [rsp+60h] [rbp-B8h]
  float v35; // [rsp+64h] [rbp-B4h]
  float v36; // [rsp+68h] [rbp-B0h]
  float v37; // [rsp+6Ch] [rbp-ACh]
  int v38; // [rsp+70h] [rbp-A8h]
  float v39; // [rsp+74h] [rbp-A4h]

  if ( this->mDebugData && !gDisableDebugDraw )
  {
    y = p0->y;
    z = p0->z;
    line_points.x = p0->x;
    line_points.y = y;
    line_points.z = z;
    v8 = p1->y;
    x = p1->x;
    v10 = p1->z;
    v11 = (__m128)LODWORD(v8);
    v11.m128_f32[0] = v8 - y;
    v12 = p1->x - line_points.x;
    v13 = v11;
    v13.m128_f32[0] = v11.m128_f32[0] * v11.m128_f32[0];
    LODWORD(v14) = COERCE_UNSIGNED_INT(v8 - y) ^ _xmm[0];
    v13.m128_f32[0] = (float)(v13.m128_f32[0] + (float)(v12 * v12)) + (float)((float)(v10 - z) * (float)(v10 - z));
    LODWORD(v15) = _mm_sqrt_ps(v13).m128_u32[0];
    v16 = (float)((float)(v12 * 15.0) * 0.0625) + line_points.x;
    *(float *)&v17 = (float)((float)((float)(v8 - y) * 15.0) * 0.0625) + y;
    v25 = v16;
    v26 = v17;
    v18 = (float)(v14 * v14) + (float)(v12 * v12);
    v19 = (float)((float)((float)(v10 - z) * 15.0) * 0.0625) + z;
    v27 = v19;
    if ( v18 <= 0.0001 )
    {
      v22 = 0.0;
      v21 = v15 * 0.03125;
      v23 = 0.0;
    }
    else
    {
      v20 = (float)(v15 * 0.03125) / fsqrt(v18);
      v21 = v20 * v14;
      v22 = v20 * v12;
      v23 = v20 * 0.0;
    }
    v31 = x;
    v32 = v8;
    v33 = v10;
    v28 = v16 + v21;
    v29 = *(float *)&v17 + v22;
    v30 = v19 + v23;
    v34 = v16 - v21;
    v35 = *(float *)&v17 - v22;
    v36 = v19 - v23;
    v37 = (float)((float)(v12 * 15.0) * 0.0625) + line_points.x;
    v38 = v17;
    v39 = (float)((float)((float)(v10 - z) * 15.0) * 0.0625) + z;
    Render::DebugDrawContext::DrawLineStrip(this, &line_points, 6, colour, local_world, pre_draw_callback);
  }
}

// File Line: 824
// RVA: 0x18B70
void __fastcall Render::DebugDrawContext::DrawPoint(
        Render::DebugDrawContext *this,
        UFG::qVector3 *point,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float y; // xmm3_4
  float v6; // xmm4_4
  float z; // xmm1_4
  UFG::qVector3 aabb_max; // [rsp+30h] [rbp-28h] BYREF
  UFG::qVector3 aabb_min; // [rsp+40h] [rbp-18h] BYREF

  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      y = point->y;
      v6 = point->x + 0.25;
      z = point->z;
      aabb_min.x = point->x - 0.25;
      aabb_min.z = z - 0.25;
      aabb_min.y = y - 0.25;
      aabb_max.x = v6;
      aabb_max.y = y + 0.25;
      aabb_max.z = z + 0.25;
      Render::DebugDrawContext::DrawAABB(this, &aabb_min, &aabb_max, colour, local_world, pre_draw_callback);
    }
  }
}

// File Line: 850
// RVA: 0x17C10
void __fastcall Render::DebugDrawContext::DrawAABB(
        Render::DebugDrawContext *this,
        UFG::qVector3 *aabb_min,
        UFG::qVector3 *aabb_max,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  Render::DebugData *mDebugData; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // rax
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  char *v16; // rax
  UFG::qNode<Render::DebugAABB,Render::DebugAABB> *v17; // rax
  UFG::qList<Render::DebugAABB,Render::DebugAABB,1,0> *p_mDebugAABB; // rdx
  UFG::qNode<Render::DebugAABB,Render::DebugAABB> *mPrev; // rcx

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    if ( local_world )
    {
      v12 = UFG::qLinearAllocator::Malloc(&mDebugData->mDebugMemory, 0x40u, 0x10u);
      v11 = (UFG::qMatrix44 *)v12;
      if ( !v12 )
      {
LABEL_10:
        this->mDebugData->mHaveExceededPool = 1;
        return;
      }
      v13 = local_world->v1;
      v14 = local_world->v2;
      v15 = local_world->v3;
      *(UFG::qVector4 *)v12 = local_world->v0;
      *((UFG::qVector4 *)v12 + 1) = v13;
      *((UFG::qVector4 *)v12 + 2) = v14;
      *((UFG::qVector4 *)v12 + 3) = v15;
    }
    else
    {
      v11 = 0i64;
    }
    v16 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x48u, 0x10u);
    if ( v16 )
    {
      Render::DebugAABB::DebugAABB((Render::DebugAABB *)v16, aabb_min, aabb_max, colour, v11, pre_draw_callback);
      if ( v17 )
      {
        p_mDebugAABB = &this->mDebugData->mDebugAABB;
        mPrev = p_mDebugAABB->mNode.mPrev;
        mPrev->mNext = v17;
        v17->mPrev = mPrev;
        v17->mNext = &p_mDebugAABB->mNode;
        p_mDebugAABB->mNode.mPrev = v17;
        return;
      }
    }
    goto LABEL_10;
  }
}

// File Line: 880
// RVA: 0x18A50
void __fastcall Render::DebugDrawContext::DrawPillar(
        Render::DebugDrawContext *this,
        UFG::qVector3 *position,
        float radius,
        float height,
        UFG::qColour *colour,
        UFG::qMatrix44 *localWorld,
        void (__fastcall *preDrawCallback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float y; // xmm5_4
  float z; // xmm4_4
  float x; // xmm6_4
  UFG::qVector3 aabb_max; // [rsp+30h] [rbp-78h] BYREF
  UFG::qVector3 aabb_min; // [rsp+3Ch] [rbp-6Ch] BYREF

  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      y = position->y;
      z = position->z;
      x = position->x;
      aabb_min.y = y - radius;
      aabb_max.x = (float)(height * 0.0) + (float)(radius + x);
      aabb_max.z = height + (float)((float)(radius * 0.0) + z);
      aabb_max.y = (float)(height * 0.0) + (float)(radius + y);
      aabb_min.z = z - (float)(radius * 0.0);
      aabb_min.x = x - radius;
      Render::DebugDrawContext::DrawAABB(this, &aabb_min, &aabb_max, colour, localWorld, preDrawCallback);
    }
  }
}

// File Line: 891
// RVA: 0x18D00
void __fastcall Render::DebugDrawContext::DrawSphere(
        Render::DebugDrawContext *this,
        UFG::qVector3 *centre,
        float radius,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  Render::DebugData *mDebugData; // rcx
  char *v11; // rdi
  char *v12; // rax
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  char *v16; // rax
  char *v17; // rdx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qList<Render::DebugSphere,Render::DebugSphere,1,0> *p_mDebugSphere; // rcx
  UFG::qNode<Render::DebugSphere,Render::DebugSphere> *mPrev; // rax

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    if ( local_world )
    {
      v12 = UFG::qLinearAllocator::Malloc(&mDebugData->mDebugMemory, 0x40u, 0x10u);
      v11 = v12;
      if ( !v12 )
      {
LABEL_9:
        this->mDebugData->mHaveExceededPool = 1;
        return;
      }
      v13 = local_world->v1;
      v14 = local_world->v2;
      v15 = local_world->v3;
      *(UFG::qVector4 *)v12 = local_world->v0;
      *((UFG::qVector4 *)v12 + 1) = v13;
      *((UFG::qVector4 *)v12 + 2) = v14;
      *((UFG::qVector4 *)v12 + 3) = v15;
    }
    else
    {
      v11 = 0i64;
    }
    v16 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x40u, 0x10u);
    v17 = v16;
    if ( v16 )
    {
      *(_QWORD *)v16 = v16;
      *((_QWORD *)v16 + 1) = v16;
      y = centre->y;
      z = centre->z;
      *((_DWORD *)v16 + 7) = LODWORD(centre->x);
      *((float *)v16 + 8) = y;
      *((float *)v16 + 9) = z;
      *((float *)v16 + 6) = radius;
      *((_DWORD *)v16 + 10) = LODWORD(colour->r);
      *((_DWORD *)v16 + 11) = LODWORD(colour->g);
      *((_DWORD *)v16 + 12) = LODWORD(colour->b);
      *((_DWORD *)v16 + 13) = LODWORD(colour->a);
      *((_QWORD *)v16 + 2) = v11;
      *((_QWORD *)v16 + 7) = pre_draw_callback;
      p_mDebugSphere = &this->mDebugData->mDebugSphere;
      mPrev = p_mDebugSphere->mNode.mPrev;
      mPrev->mNext = (UFG::qNode<Render::DebugSphere,Render::DebugSphere> *)v17;
      *(_QWORD *)v17 = mPrev;
      *((_QWORD *)v17 + 1) = p_mDebugSphere;
      p_mDebugSphere->mNode.mPrev = (UFG::qNode<Render::DebugSphere,Render::DebugSphere> *)v17;
      return;
    }
    goto LABEL_9;
  }
}

// File Line: 921
// RVA: 0x18500
void __fastcall Render::DebugDrawContext::DrawCylinder(
        Render::DebugDrawContext *this,
        UFG::qVector3 *min,
        UFG::qVector3 *max,
        float radius,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  Render::DebugData *mDebugData; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // rax
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  char *v16; // rax
  UFG::qNode<Render::DebugCylinder,Render::DebugCylinder> *v17; // rax
  UFG::qList<Render::DebugCylinder,Render::DebugCylinder,1,0> *p_mDebugCylinder; // rdx
  UFG::qNode<Render::DebugCylinder,Render::DebugCylinder> *mPrev; // rcx

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    if ( local_world )
    {
      v12 = UFG::qLinearAllocator::Malloc(&mDebugData->mDebugMemory, 0x40u, 0x10u);
      v11 = (UFG::qMatrix44 *)v12;
      if ( !v12 )
      {
LABEL_10:
        this->mDebugData->mHaveExceededPool = 1;
        return;
      }
      v13 = local_world->v1;
      v14 = local_world->v2;
      v15 = local_world->v3;
      *(UFG::qVector4 *)v12 = local_world->v0;
      *((UFG::qVector4 *)v12 + 1) = v13;
      *((UFG::qVector4 *)v12 + 2) = v14;
      *((UFG::qVector4 *)v12 + 3) = v15;
    }
    else
    {
      v11 = 0i64;
    }
    v16 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x50u, 0x10u);
    if ( v16 )
    {
      Render::DebugCylinder::DebugCylinder(
        (Render::DebugCylinder *)v16,
        min,
        max,
        radius,
        colour,
        v11,
        pre_draw_callback);
      if ( v17 )
      {
        p_mDebugCylinder = &this->mDebugData->mDebugCylinder;
        mPrev = p_mDebugCylinder->mNode.mPrev;
        mPrev->mNext = v17;
        v17->mPrev = mPrev;
        v17->mNext = &p_mDebugCylinder->mNode;
        p_mDebugCylinder->mNode.mPrev = v17;
        return;
      }
    }
    goto LABEL_10;
  }
}

// File Line: 961
// RVA: 0x182F0
void __fastcall Render::DebugDrawContext::DrawCircle(
        Render::DebugDrawContext *this,
        UFG::qVector3 *centre,
        float radius,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  UFG::qVector3 normal; // [rsp+40h] [rbp-18h] BYREF

  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      LODWORD(normal.z) = (_DWORD)FLOAT_1_0;
      *(_QWORD *)&normal.x = 0i64;
      Render::DebugDrawContext::DrawCircle(this, centre, &normal, radius, colour, local_world, pre_draw_callback);
    }
  }
}

// File Line: 969
// RVA: 0x181E0
void __fastcall Render::DebugDrawContext::DrawCircle(
        Render::DebugDrawContext *this,
        UFG::qVector3 *centre,
        UFG::qVector3 *normal,
        float radius,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  Render::DebugData *mDebugData; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // rax
  UFG::qNode<Render::DebugCircle,Render::DebugCircle> *v13; // rax
  UFG::qList<Render::DebugCircle,Render::DebugCircle,1,0> *p_mDebugCircle; // rdx
  UFG::qNode<Render::DebugCircle,Render::DebugCircle> *mPrev; // rcx

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    v11 = 0i64;
    if ( (!local_world || (v11 = Render::DebugData::AllocMatrix(mDebugData, local_world)) != 0i64)
      && (v12 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x50u, 0x10u)) != 0i64
      && (Render::DebugCircle::DebugCircle(
            (Render::DebugCircle *)v12,
            centre,
            normal,
            radius,
            colour,
            v11,
            pre_draw_callback),
          v13) )
    {
      p_mDebugCircle = &this->mDebugData->mDebugCircle;
      mPrev = p_mDebugCircle->mNode.mPrev;
      mPrev->mNext = v13;
      v13->mPrev = mPrev;
      v13->mNext = &p_mDebugCircle->mNode;
      p_mDebugCircle->mNode.mPrev = v13;
    }
    else
    {
      this->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1004
// RVA: 0x17D40
void __fastcall Render::DebugDrawContext::DrawArc(
        Render::DebugDrawContext *this,
        float radius,
        float minAngle,
        float maxAngle,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  Render::DebugData *mDebugData; // rcx
  UFG::qMatrix44 *v9; // rdi
  char *v10; // rax
  char *v11; // rdx
  UFG::qList<Render::DebugArc,Render::DebugArc,1,0> *p_mDebugArc; // rcx
  UFG::qNode<Render::DebugArc,Render::DebugArc> *mPrev; // rax

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    v9 = 0i64;
    if ( (!local_world || (v9 = Render::DebugData::AllocMatrix(mDebugData, local_world)) != 0i64)
      && (v10 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x40u, 0x10u), (v11 = v10) != 0i64) )
    {
      *(_QWORD *)v10 = v10;
      *((_QWORD *)v10 + 1) = v10;
      *((float *)v10 + 7) = minAngle;
      *((float *)v10 + 8) = maxAngle;
      *((float *)v10 + 6) = radius;
      *(UFG::qColour *)(v10 + 36) = *colour;
      *((_QWORD *)v10 + 2) = v9;
      *((_QWORD *)v10 + 7) = pre_draw_callback;
      p_mDebugArc = &this->mDebugData->mDebugArc;
      mPrev = p_mDebugArc->mNode.mPrev;
      mPrev->mNext = (UFG::qNode<Render::DebugArc,Render::DebugArc> *)v11;
      *(_QWORD *)v11 = mPrev;
      *((_QWORD *)v11 + 1) = p_mDebugArc;
      p_mDebugArc->mNode.mPrev = (UFG::qNode<Render::DebugArc,Render::DebugArc> *)v11;
    }
    else
    {
      this->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1037
// RVA: 0x188A0
void __fastcall Render::DebugDrawContext::DrawLineStrip(
        Render::DebugDrawContext *this,
        UFG::qVector3 *line_points,
        int num_points,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  Render::DebugData *mDebugData; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // r10
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v13; // rax
  UFG::qList<Render::DebugLineStrip,Render::DebugLineStrip,1,0> *p_mDebugLineStrips; // rdx
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *mPrev; // rcx
  UFG::DrawInfo info; // [rsp+40h] [rbp-58h] BYREF

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    v11 = 0i64;
    if ( local_world )
    {
      v11 = Render::DebugData::AllocMatrix(mDebugData, local_world);
      if ( !v11 )
        goto LABEL_9;
    }
    v12 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x60u, 0x10u);
    if ( !v12 )
      goto LABEL_9;
    info.mScale = UFG::DrawInfo::msDefault.mScale;
    info.mAlphaBlend = UFG::DrawInfo::msDefault.mAlphaBlend;
    info.mDepthBuffer = UFG::DrawInfo::msDefault.mDepthBuffer;
    info.mFaceCull = UFG::DrawInfo::msDefault.mFaceCull;
    info.mDepthBias = UFG::DrawInfo::msDefault.mDepthBias;
    info.mColour1.r = colour->r;
    info.mColour1.g = colour->g;
    info.mColour1.b = colour->b;
    info.mColour1.a = colour->a;
    info.mColour2 = *colour;
    info.mPreDrawCallback = pre_draw_callback;
    Render::DebugLineStrip::DebugLineStrip(
      (Render::DebugLineStrip *)v12,
      &this->mDebugData->mDebugMemory,
      line_points,
      num_points,
      &info,
      v11);
    if ( !v13 )
      goto LABEL_9;
    if ( v13[1].mPrev )
    {
      p_mDebugLineStrips = &this->mDebugData->mDebugLineStrips;
      mPrev = p_mDebugLineStrips->mNode.mPrev;
      mPrev->mNext = v13;
      v13->mPrev = mPrev;
      v13->mNext = &p_mDebugLineStrips->mNode;
      p_mDebugLineStrips->mNode.mPrev = v13;
    }
    else
    {
LABEL_9:
      this->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1073
// RVA: 0x18760
void __fastcall Render::DebugDrawContext::DrawLineStrip(
        Render::DebugDrawContext *this,
        UFG::qVector3 *line_points,
        int num_points,
        UFG::DrawInfo *info,
        UFG::qMatrix44 *local_world)
{
  Render::DebugData *mDebugData; // rcx
  UFG::qMatrix44 *v10; // rdi
  char *v11; // rax
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  char *v15; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v16; // rax
  UFG::qList<Render::DebugLineStrip,Render::DebugLineStrip,1,0> *p_mDebugLineStrips; // rdx
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *mPrev; // rcx

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    if ( local_world )
    {
      v11 = UFG::qLinearAllocator::Malloc(&mDebugData->mDebugMemory, 0x40u, 0x10u);
      v10 = (UFG::qMatrix44 *)v11;
      if ( !v11 )
      {
LABEL_11:
        this->mDebugData->mHaveExceededPool = 1;
        return;
      }
      v12 = local_world->v1;
      v13 = local_world->v2;
      v14 = local_world->v3;
      *(UFG::qVector4 *)v11 = local_world->v0;
      *((UFG::qVector4 *)v11 + 1) = v12;
      *((UFG::qVector4 *)v11 + 2) = v13;
      *((UFG::qVector4 *)v11 + 3) = v14;
    }
    else
    {
      v10 = 0i64;
    }
    v15 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x60u, 0x10u);
    if ( v15 )
    {
      Render::DebugLineStrip::DebugLineStrip(
        (Render::DebugLineStrip *)v15,
        &this->mDebugData->mDebugMemory,
        line_points,
        num_points,
        info,
        v10);
      if ( v16 )
      {
        if ( v16[1].mPrev )
        {
          p_mDebugLineStrips = &this->mDebugData->mDebugLineStrips;
          mPrev = p_mDebugLineStrips->mNode.mPrev;
          mPrev->mNext = v16;
          v16->mPrev = mPrev;
          v16->mNext = &p_mDebugLineStrips->mNode;
          p_mDebugLineStrips->mNode.mPrev = v16;
          return;
        }
      }
    }
    goto LABEL_11;
  }
}

// File Line: 1099
// RVA: 0x19290
void __fastcall Render::DebugDrawContext::DrawTriStrip(
        Render::DebugDrawContext *this,
        UFG::qVector3 *tri_points,
        int num_points,
        UFG::DrawInfo *info,
        UFG::qMatrix44 *local_world,
        bool is_screen_coords)
{
  Render::DebugData *mDebugData; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v13; // rax
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *p_mDebugTriStrips; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *mPrev; // rcx

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    v11 = 0i64;
    if ( (!local_world || (v11 = Render::DebugData::AllocMatrix(mDebugData, local_world)) != 0i64)
      && (v12 = UFG::qLinearAllocator::Malloc(&this->mDebugData->mDebugMemory, 0x68u, 0x10u)) != 0i64
      && (Render::DebugTriStrip::DebugTriStrip(
            (Render::DebugTriStrip *)v12,
            &this->mDebugData->mDebugMemory,
            tri_points,
            num_points,
            info,
            v11,
            is_screen_coords),
          v13)
      && v13[5].mNext )
    {
      p_mDebugTriStrips = &this->mDebugData->mDebugTriStrips;
      mPrev = p_mDebugTriStrips->mNode.mPrev;
      mPrev->mNext = v13;
      v13->mPrev = mPrev;
      v13->mNext = &p_mDebugTriStrips->mNode;
      p_mDebugTriStrips->mNode.mPrev = v13;
    }
    else
    {
      this->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1125
// RVA: 0x180F0
void __fastcall Render::DebugDrawContext::DrawAxes(
        Render::DebugDrawContext *this,
        UFG::qMatrix44 *xform,
        float scale,
        char depth_buffer,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  Render::DebugData *mDebugData; // rcx
  char *v10; // rax
  char *v11; // rdx
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  UFG::qList<Render::DebugAxis,Render::DebugAxis,1,0> *p_mDebugAxis; // rcx
  UFG::qNode<Render::DebugAxis,Render::DebugAxis> *mPrev; // rax

  mDebugData = this->mDebugData;
  if ( mDebugData && !gDisableDebugDraw )
  {
    v10 = UFG::qLinearAllocator::Malloc(&mDebugData->mDebugMemory, 0x60u, 0x10u);
    v11 = v10;
    if ( v10 )
    {
      *(_QWORD *)v10 = v10;
      *((_QWORD *)v10 + 1) = v10;
      v12 = xform->v1;
      v13 = xform->v2;
      v14 = xform->v3;
      *((_OWORD *)v10 + 1) = xform->v0;
      *((UFG::qVector4 *)v10 + 2) = v12;
      *((UFG::qVector4 *)v10 + 3) = v13;
      *((UFG::qVector4 *)v10 + 4) = v14;
      *((float *)v10 + 20) = scale;
      v10[84] = depth_buffer;
      *((_QWORD *)v10 + 11) = pre_draw_callback;
      p_mDebugAxis = &this->mDebugData->mDebugAxis;
      mPrev = p_mDebugAxis->mNode.mPrev;
      mPrev->mNext = (UFG::qNode<Render::DebugAxis,Render::DebugAxis> *)v11;
      *(_QWORD *)v11 = mPrev;
      *((_QWORD *)v11 + 1) = p_mDebugAxis;
      p_mDebugAxis->mNode.mPrev = (UFG::qNode<Render::DebugAxis,Render::DebugAxis> *)v11;
    }
    else
    {
      this->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1148
// RVA: 0x18350
void __fastcall Render::DebugDrawContext::DrawCoord(
        Render::DebugDrawContext *this,
        UFG::qMatrix44 *xform,
        float scale,
        const char *text)
{
  float y; // xmm4_4
  float z; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::qVector3 p0; // [rsp+40h] [rbp-38h] BYREF
  UFG::qVector3 p1; // [rsp+4Ch] [rbp-2Ch] BYREF

  y = xform->v3.y;
  z = xform->v3.z;
  v8 = scale * xform->v0.x;
  v9 = scale * xform->v0.y;
  p0.x = xform->v3.x;
  p0.y = y;
  p0.z = z;
  v11 = z + (float)(scale * xform->v0.z);
  p1.x = p0.x + v8;
  p1.y = y + v9;
  p1.z = v11;
  Render::DebugDrawContext::DrawLine(
    this,
    &p0,
    &p1,
    &UFG::qColour::Red,
    &UFG::qMatrix44::msIdentity,
    (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
    0);
  v12 = (float)(scale * xform->v1.y) + xform->v3.y;
  v13 = (float)(scale * xform->v1.z) + xform->v3.z;
  p1.x = (float)(scale * xform->v1.x) + xform->v3.x;
  p1.y = v12;
  p1.z = v13;
  Render::DebugDrawContext::DrawLine(
    this,
    &p0,
    &p1,
    &UFG::qColour::Yellow,
    &UFG::qMatrix44::msIdentity,
    (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
    0);
  v14 = (float)(scale * xform->v2.x) + xform->v3.x;
  v15 = (float)(scale * xform->v2.y) + xform->v3.y;
  p1.z = (float)(scale * xform->v2.z) + xform->v3.z;
  p1.x = v14;
  p1.y = v15;
  Render::DebugDrawContext::DrawLine(
    this,
    &p0,
    &p1,
    &UFG::qColour::Blue,
    &UFG::qMatrix44::msIdentity,
    (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
    0);
  if ( text )
    Render::DebugDrawContext::DrawText(this, &p0, &UFG::qColour::Green, "%s", text);
}

// File Line: 1183
// RVA: 0x177F0
void __fastcall Render::DebugDrawContext::Clear(Render::DebugDrawContext *this)
{
  Render::DebugData *mDebugData; // rdx
  UFG::qList<Render::DebugAABB,Render::DebugAABB,1,0> *p_mDebugAABB; // rax
  UFG::qList<Render::DebugLineStrip,Render::DebugLineStrip,1,0> *p_mDebugLineStrips; // rax
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *p_mDebugTriStrips; // rax
  UFG::qList<Render::DebugRect,Render::DebugRect,1,0> *p_mDebugRects; // rax
  UFG::qList<Render::DebugSphere,Render::DebugSphere,1,0> *p_mDebugSphere; // rax
  UFG::qList<Render::DebugCylinder,Render::DebugCylinder,1,0> *p_mDebugCylinder; // rax
  UFG::qList<Render::DebugCircle,Render::DebugCircle,1,0> *p_mDebugCircle; // rax
  UFG::qList<Render::DebugArc,Render::DebugArc,1,0> *p_mDebugArc; // rax
  UFG::qList<Render::DebugAxis,Render::DebugAxis,1,0> *p_mDebugAxis; // rax
  UFG::qList<Render::DebugText,Render::DebugText,1,0> *p_mDebugTextLines; // rax
  UFG::qList<Render::DebugIcon,Render::DebugIcon,1,0> *p_mDebugIcons; // rax

  mDebugData = this->mDebugData;
  if ( mDebugData )
  {
    UFG::qLinearAllocator::Init(
      &mDebugData->mDebugMemory,
      mDebugData->mDebugPool,
      mDebugData->mDebugPoolSize,
      0i64,
      0i64);
    p_mDebugAABB = &this->mDebugData->mDebugAABB;
    p_mDebugAABB->mNode.mPrev = &p_mDebugAABB->mNode;
    p_mDebugAABB->mNode.mNext = &p_mDebugAABB->mNode;
    p_mDebugLineStrips = &this->mDebugData->mDebugLineStrips;
    p_mDebugLineStrips->mNode.mPrev = &p_mDebugLineStrips->mNode;
    p_mDebugLineStrips->mNode.mNext = &p_mDebugLineStrips->mNode;
    p_mDebugTriStrips = &this->mDebugData->mDebugTriStrips;
    p_mDebugTriStrips->mNode.mPrev = &p_mDebugTriStrips->mNode;
    p_mDebugTriStrips->mNode.mNext = &p_mDebugTriStrips->mNode;
    p_mDebugRects = &this->mDebugData->mDebugRects;
    p_mDebugRects->mNode.mPrev = &p_mDebugRects->mNode;
    p_mDebugRects->mNode.mNext = &p_mDebugRects->mNode;
    p_mDebugSphere = &this->mDebugData->mDebugSphere;
    p_mDebugSphere->mNode.mPrev = &p_mDebugSphere->mNode;
    p_mDebugSphere->mNode.mNext = &p_mDebugSphere->mNode;
    p_mDebugCylinder = &this->mDebugData->mDebugCylinder;
    p_mDebugCylinder->mNode.mPrev = &p_mDebugCylinder->mNode;
    p_mDebugCylinder->mNode.mNext = &p_mDebugCylinder->mNode;
    p_mDebugCircle = &this->mDebugData->mDebugCircle;
    p_mDebugCircle->mNode.mPrev = &p_mDebugCircle->mNode;
    p_mDebugCircle->mNode.mNext = &p_mDebugCircle->mNode;
    p_mDebugArc = &this->mDebugData->mDebugArc;
    p_mDebugArc->mNode.mPrev = &p_mDebugArc->mNode;
    p_mDebugArc->mNode.mNext = &p_mDebugArc->mNode;
    p_mDebugAxis = &this->mDebugData->mDebugAxis;
    p_mDebugAxis->mNode.mPrev = &p_mDebugAxis->mNode;
    p_mDebugAxis->mNode.mNext = &p_mDebugAxis->mNode;
    p_mDebugTextLines = &this->mDebugData->mDebugTextLines;
    p_mDebugTextLines->mNode.mPrev = &p_mDebugTextLines->mNode;
    p_mDebugTextLines->mNode.mNext = &p_mDebugTextLines->mNode;
    p_mDebugIcons = &this->mDebugData->mDebugIcons;
    p_mDebugIcons->mNode.mPrev = &p_mDebugIcons->mNode;
    p_mDebugIcons->mNode.mNext = &p_mDebugIcons->mNode;
    this->mDebugData->mHaveExceededPool = 0;
    UFG::qLinearAllocator::Reset(&this->mDebugData->mDebugMemory);
  }
}

// File Line: 1208
// RVA: 0x17A70
bool __fastcall Render::CompareTristrips(Render::DebugTriStrip *a, Render::DebugTriStrip *b)
{
  return b->mSortMetric < a->mSortMetric;
}

// File Line: 1213
// RVA: 0x193A0
void __fastcall Render::DebugDrawContext::Flush(Render::DebugDrawContext *this)
{
  float TargetWidth; // xmm9_4
  int TargetHeight; // eax
  UFG::qNode<Render::DebugRect,Render::DebugRect> *mNext; // rdi
  float i; // xmm10_4
  Render::DebugData *mDebugData; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v7; // rdi
  int mPrev; // eax
  unsigned int v9; // r10d
  __int64 v10; // r9
  __int64 v11; // rcx
  unsigned __int64 v12; // r8
  float v13; // xmm2_4
  float v14; // xmm3_4
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v15; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v16; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v17; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rdx
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v21; // rax
  float v22; // xmm1_4
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *j; // rdx
  float *v24; // rcx
  int v25; // eax
  __int64 v26; // r8
  __int64 v27; // r10
  __int64 v28; // rcx
  unsigned __int64 v29; // r9
  float v30; // xmm2_4
  float v31; // xmm3_4
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v32; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v33; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v34; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v35; // rax
  __int64 v36; // rcx
  __int64 v37; // r8
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v38; // rax
  float v39; // xmm1_4
  float *v40; // r9
  float v41; // xmm6_4
  float v42; // xmm7_4
  float v43; // xmm5_4
  float v44; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm7_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  Render::DebugData *v50; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v51; // rdi
  UFG::qVector3 *v52; // rdx
  UFG::qNode<Render::DebugAABB,Render::DebugAABB> *k; // rdi
  UFG::qNode<Render::DebugSphere,Render::DebugSphere> *m; // rdi
  UFG::qNode<Render::DebugCylinder,Render::DebugCylinder> *n; // rdi
  UFG::qNode<Render::DebugCircle,Render::DebugCircle> *ii; // rdi
  Render::DebugData *v57; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v58; // rdi
  Render::View *mView; // rcx
  float v60; // xmm0_4
  UFG::qNode<Render::DebugAxis,Render::DebugAxis> *jj; // rdi
  Render::DebugData *v62; // rcx
  UFG::qNode<Render::DebugText,Render::DebugText> *v63; // rdi
  Render::Font *mData; // rsi
  float v65; // xmm6_4
  int v66; // eax
  Render::View *v67; // r8
  int mPrev_high; // ecx
  float v69; // xmm1_4
  float v70; // xmm1_4
  int v71; // ecx
  __m128i v72; // xmm0
  __m128i v73; // xmm0
  UFG::qNode<Render::DebugIcon,Render::DebugIcon> *kk; // rdi
  int v75; // ecx
  int v76; // eax
  unsigned int v77; // edx
  UFG::qColour *colour_right; // [rsp+30h] [rbp-C0h]
  UFG::qColour v79; // [rsp+40h] [rbp-B0h] BYREF
  UFG::DrawInfo info; // [rsp+50h] [rbp-A0h] BYREF
  int w; // [rsp+110h] [rbp+20h] BYREF
  void *retaddr; // [rsp+118h] [rbp+28h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+120h] [rbp+30h] BYREF

  if ( this->mDebugData && !gDisableDebugDraw )
  {
    TargetWidth = (float)(int)Render::View::GetTargetWidth(this->mView);
    TargetHeight = Render::View::GetTargetHeight(this->mView);
    mNext = this->mDebugData->mDebugRects.mNode.mNext;
    for ( i = (float)TargetHeight; mNext != &this->mDebugData->mDebugRects.mNode; mNext = mNext->mNext )
      Render::View::DrawGradient(
        this->mView,
        (int)*(float *)&mNext[1].mPrev,
        (int)*((float *)&mNext[1].mPrev + 1),
        (int)*(float *)&mNext[1].mNext,
        (int)*((float *)&mNext[1].mNext + 1),
        (UFG::qColour *)&mNext[2],
        (UFG::qColour *)&mNext[2]);
    mDebugData = this->mDebugData;
    v7 = mDebugData->mDebugLineStrips.mNode.mNext;
    if ( v7 != (UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *)&mDebugData->mDebugLineStrips )
    {
      do
      {
        if ( v7[1].mPrev )
        {
          mPrev = (int)v7[2].mPrev;
          v9 = (unsigned __int16)mPrev;
          if ( (mPrev & 0x10000) != 0 )
          {
            v10 = 0i64;
            if ( (unsigned __int16)mPrev >= 4ui64 )
            {
              v11 = 0i64;
              v12 = (((unsigned __int64)(unsigned __int16)mPrev - 4) >> 2) + 1;
              v13 = 1.0 / TargetWidth;
              v14 = 1.0 / i;
              v10 = 4 * v12;
              do
              {
                v15 = v7[1].mPrev;
                v11 += 3i64;
                *(float *)&v15[v11 - 3].mPrev = v13 * *(float *)&v15[v11 - 3].mPrev;
                *((float *)&v15[v11 - 2] - 3) = v14 * *((float *)&v15[v11 - 2] - 3);
                v16 = v7[1].mPrev;
                *((float *)&v16[v11 - 2] - 1) = v13 * *((float *)&v16[v11 - 2] - 1);
                *(float *)&v16[v11 - 2].mPrev = v14 * *(float *)&v16[v11 - 2].mPrev;
                v17 = v7[1].mPrev;
                *((float *)&v17[v11 - 1] - 2) = v13 * *((float *)&v17[v11 - 1] - 2);
                *((float *)&v17[v11 - 1] - 1) = v14 * *((float *)&v17[v11 - 1] - 1);
                v18 = v7[1].mPrev;
                *((float *)&v18[v11 - 1].mPrev + 1) = v13 * *((float *)&v18[v11 - 1].mPrev + 1);
                *(float *)&v18[v11 - 1].mNext = v14 * *(float *)&v18[v11 - 1].mNext;
                --v12;
              }
              while ( v12 );
            }
            if ( v10 < v9 )
            {
              v19 = 12 * v10;
              v20 = v9 - v10;
              do
              {
                v21 = v7[1].mPrev;
                v19 += 12i64;
                v22 = (float)(1.0 / i) * *(float *)((char *)v21 + v19 - 8);
                *(float *)((char *)v21 + v19 - 12) = (float)(1.0 / TargetWidth) * *(float *)((char *)v21 + v19 - 12);
                *(float *)((char *)v21 + v19 - 8) = v22;
                --v20;
              }
              while ( v20 );
            }
          }
          if ( (this->mFeatureFlags & 2) == 0 )
            LOBYTE(v7[5].mPrev) = 0;
          Render::View::DrawDebugPrimLineStrip(
            this->mView,
            (UFG::qVector3 *)v7[1].mPrev,
            v9,
            (UFG::DrawInfo *)&v7[2].mNext,
            (UFG::qMatrix44 *)v7[1].mNext);
        }
        v7 = v7->mNext;
      }
      while ( v7 != &this->mDebugData->mDebugLineStrips.mNode );
    }
    for ( j = this->mDebugData->mDebugTriStrips.mNode.mNext; j != &this->mDebugData->mDebugTriStrips.mNode; j = j->mNext )
    {
      v24 = (float *)j[5].mNext;
      v25 = (int)j[1].mPrev;
      if ( v24 && (_WORD)v25 )
      {
        LODWORD(j[6].mPrev) = 0;
        v26 = (unsigned __int16)v25;
        if ( (v25 & 0x10000) != 0 )
        {
          v27 = 0i64;
          if ( (unsigned __int16)v25 >= 4ui64 )
          {
            v28 = 0i64;
            v29 = (((unsigned __int64)(unsigned __int16)v25 - 4) >> 2) + 1;
            v30 = 1.0 / TargetWidth;
            v31 = 1.0 / i;
            v27 = 4 * v29;
            do
            {
              v32 = j[5].mNext;
              v28 += 3i64;
              *(float *)&v32[v28 - 3].mPrev = v30 * *(float *)&v32[v28 - 3].mPrev;
              *((float *)&v32[v28 - 2] - 3) = v31 * *((float *)&v32[v28 - 2] - 3);
              v33 = j[5].mNext;
              *((float *)&v33[v28 - 2] - 1) = v30 * *((float *)&v33[v28 - 2] - 1);
              *(float *)&v33[v28 - 2].mPrev = v31 * *(float *)&v33[v28 - 2].mPrev;
              v34 = j[5].mNext;
              *((float *)&v34[v28 - 1] - 2) = v30 * *((float *)&v34[v28 - 1] - 2);
              *((float *)&v34[v28 - 1] - 1) = v31 * *((float *)&v34[v28 - 1] - 1);
              v35 = j[5].mNext;
              *((float *)&v35[v28 - 1].mPrev + 1) = v30 * *((float *)&v35[v28 - 1].mPrev + 1);
              *(float *)&v35[v28 - 1].mNext = v31 * *(float *)&v35[v28 - 1].mNext;
              --v29;
            }
            while ( v29 );
          }
          if ( v27 < v26 )
          {
            v36 = 12 * v27;
            v37 = v26 - v27;
            do
            {
              v38 = j[5].mNext;
              v36 += 12i64;
              v39 = (float)(1.0 / i) * *(float *)((char *)v38 + v36 - 8);
              *(float *)((char *)v38 + v36 - 12) = (float)(1.0 / TargetWidth) * *(float *)((char *)v38 + v36 - 12);
              *(float *)((char *)v38 + v36 - 8) = v39;
              --v37;
            }
            while ( v37 );
          }
        }
        else
        {
          v40 = (float *)j[5].mPrev;
          if ( v40 )
          {
            do
            {
              v41 = v24[1];
              v42 = (float)((float)((float)(v41 * v40[4]) + (float)(*v24 * *v40)) + (float)(v24[2] * v40[8])) + v40[12];
              v43 = (float)((float)((float)(v41 * v40[5]) + (float)(*v24 * v40[1])) + (float)(v24[2] * v40[9]))
                  + v40[13];
              v44 = (float)((float)((float)(v41 * v40[6]) + (float)(*v24 * v40[2])) + (float)(v24[2] * v40[10]))
                  + v40[14];
              v45 = (float)(v42 * this->mView->mWorldViewProjection.v0.z)
                  + (float)(v43 * this->mView->mWorldViewProjection.v1.z);
              v46 = (float)((float)((float)(v41 * v40[7]) + (float)(*v24 * v40[3])) + (float)(v24[2] * v40[11]))
                  + v40[15];
              v47 = (float)((float)((float)(v42 * this->mView->mWorldViewProjection.v0.w)
                                  + (float)(v43 * this->mView->mWorldViewProjection.v1.w))
                          + (float)(v44 * this->mView->mWorldViewProjection.v2.w))
                  + (float)(v46 * this->mView->mWorldViewProjection.v3.w);
              v48 = (float)(v45 + (float)(v44 * this->mView->mWorldViewProjection.v2.z))
                  + (float)(v46 * this->mView->mWorldViewProjection.v3.z);
              if ( v47 != 0.0 )
                *(float *)&j[6].mPrev = (float)(v48 / v47) + *(float *)&j[6].mPrev;
              v24 += 3;
              --v26;
            }
            while ( v26 );
            v49 = *(float *)&j[6].mPrev / (float)(unsigned __int16)v25;
            *(float *)&j[6].mPrev = v49;
            if ( BYTE4(j[6].mPrev) )
              *(float *)&j[6].mPrev = v49 - 1.0;
          }
        }
        if ( (this->mFeatureFlags & 2) == 0 )
          LOBYTE(j[4].mPrev) = 0;
      }
    }
    UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(
      &this->mDebugData->mDebugTriStrips,
      Render::CompareTristrips);
    v50 = this->mDebugData;
    v51 = v50->mDebugTriStrips.mNode.mNext;
    if ( v51 != (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v50->mDebugTriStrips )
    {
      do
      {
        v52 = (UFG::qVector3 *)v51[5].mNext;
        if ( v52 && LOWORD(v51[1].mPrev) )
          Render::View::DrawDebugPrimTriStrip(
            this->mView,
            v52,
            LOWORD(v51[1].mPrev),
            (UFG::DrawInfo *)&v51[1].mNext,
            (UFG::qMatrix44 *)v51[5].mPrev);
        v51 = v51->mNext;
      }
      while ( v51 != &this->mDebugData->mDebugTriStrips.mNode );
    }
    for ( k = this->mDebugData->mDebugAABB.mNode.mNext; k != &this->mDebugData->mDebugAABB.mNode; k = k->mNext )
      Render::View::DrawDebugPrimAABB(
        this->mView,
        (UFG::qVector3 *)&k[2].mNext,
        (UFG::qVector3 *)((char *)&k[3].mPrev + 4),
        (UFG::qColour *)&k[1].mNext);
    for ( m = this->mDebugData->mDebugSphere.mNode.mNext; m != &this->mDebugData->mDebugSphere.mNode; m = m->mNext )
      Render::View::DrawDebugPrimSphere(
        this->mView,
        (UFG::qVector3 *)((char *)&m[1].mNext + 4),
        *(const float *)&m[1].mNext,
        (UFG::qColour *)&m[2].mNext,
        (UFG::qMatrix44 *)m[1].mPrev,
        (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))m[3].mNext);
    for ( n = this->mDebugData->mDebugCylinder.mNode.mNext; n != &this->mDebugData->mDebugCylinder.mNode; n = n->mNext )
    {
      colour_right = (UFG::qColour *)n[4].mNext;
      Render::View::DrawDebugPrimCylinder(
        this->mView,
        (UFG::qVector3 *)&n[1].mNext,
        (UFG::qVector3 *)((char *)&n[2].mPrev + 4),
        *(const float *)&n[3].mPrev);
    }
    for ( ii = this->mDebugData->mDebugCircle.mNode.mNext; ii != &this->mDebugData->mDebugCircle.mNode; ii = ii->mNext )
      Render::View::DrawDebugPrimCircle(
        this->mView,
        (UFG::qVector3 *)((char *)&ii[1].mNext + 4),
        (UFG::qVector3 *)&ii[2].mNext,
        *(const float *)&ii[1].mNext,
        (UFG::qColour *)((char *)&ii[3].mPrev + 4),
        (UFG::qMatrix44 *)ii[1].mPrev,
        (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))ii[4].mNext);
    v57 = this->mDebugData;
    *(_WORD *)&info.mDepthBuffer = 257;
    info.mColour1 = UFG::qColour::White;
    info.mDepthBias = 0;
    *(_QWORD *)&info.mScale = 0i64;
    v57 = (Render::DebugData *)((char *)v57 + 176);
    info.mColour2 = UFG::qColour::White;
    v58 = v57->mDebugFontHandle.mNext;
    if ( v58 != (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v57 )
    {
      do
      {
        mView = this->mView;
        info.mColour1.r = *((float *)&v58[2].mPrev + 1);
        info.mColour1.g = *(float *)&v58[2].mNext;
        info.mColour1.b = *((float *)&v58[2].mNext + 1);
        info.mColour1.a = *(float *)&v58[3].mPrev;
        info.mColour2 = *(UFG::qColour *)((char *)v58 + 36);
        v60 = *(float *)&v58[1].mNext;
        info.mAlphaBlend = AlphaState_modulated;
        info.mScale = v60 * 2.0;
        *(_QWORD *)&info.mScale = v58[3].mNext;
        Render::View::DrawArcSolid(
          mView,
          (UFG::qMatrix44 *)v58[1].mPrev,
          &info,
          *((float *)&v58[1].mNext + 1),
          *(float *)&v58[2].mPrev,
          0x14u);
        v58 = v58->mNext;
      }
      while ( v58 != (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&this->mDebugData->mDebugArc );
    }
    for ( jj = this->mDebugData->mDebugAxis.mNode.mNext; jj != &this->mDebugData->mDebugAxis.mNode; jj = jj->mNext )
      Render::View::DrawAxes(this->mView, (UFG::qMatrix44 *)&jj[1], *(float *)&jj[5].mPrev, BYTE4(jj[5].mPrev));
    v62 = this->mDebugData;
    v63 = v62->mDebugTextLines.mNode.mNext;
    if ( v63 != (UFG::qNode<Render::DebugText,Render::DebugText> *)&v62->mDebugTextLines )
    {
      while ( 1 )
      {
        mData = (Render::Font *)v63[1].mNext[1].mPrev;
        if ( !mData )
          mData = (Render::Font *)v62->mDebugFontHandle.mData;
        if ( LODWORD(v63[3].mPrev) )
        {
          v65 = (float)(int)Render::View::GetTargetHeight(this->mView);
          v66 = Render::View::GetTargetWidth(this->mView);
          v67 = this->mView;
          viewport_scale.y = v65;
          viewport_scale.x = (float)v66;
          UFG::qGetScreenCoord(
            (UFG::qVector3 *)&v79,
            (UFG::qVector3 *)&v63[3].mNext,
            &v67->mWorldViewProjection,
            &viewport_scale,
            0i64);
          if ( HIDWORD(v63[3].mPrev) != 9 )
          {
            Render::Font::Measure(mData, &w, (int *)&retaddr, (const char *)v63[1].mPrev);
            mPrev_high = HIDWORD(v63[3].mPrev);
            if ( (mPrev_high & 4) != 0 )
            {
              v69 = v79.r - (float)w;
              goto LABEL_64;
            }
            if ( (mPrev_high & 2) != 0 )
            {
              v69 = v79.r + (float)(w / -2);
LABEL_64:
              v79.r = v69;
            }
            if ( (mPrev_high & 0x20) != 0 )
            {
              v70 = v79.g - (float)(int)retaddr;
              goto LABEL_69;
            }
            if ( (mPrev_high & 0x10) != 0 )
            {
              v70 = v79.g + (float)((int)retaddr / -2);
LABEL_69:
              v79.g = v70;
            }
          }
          if ( v79.b > 0.0 && v79.b < 1.0 )
            Render::Font::Print(
              mData,
              this->mView,
              (int)v79.r,
              (int)v79.g,
              (UFG::qColour *)&v63[2],
              (char *)v63[1].mPrev,
              colour_right);
          goto LABEL_85;
        }
        if ( HIDWORD(v63[3].mPrev) == 9 )
          goto LABEL_84;
        Render::Font::Measure(mData, &w, (int *)&retaddr, (const char *)v63[1].mPrev);
        v71 = HIDWORD(v63[3].mPrev);
        if ( (v71 & 4) != 0 )
          break;
        if ( (v71 & 2) != 0 )
        {
          v72 = _mm_cvtsi32_si128(w / 2);
          goto LABEL_78;
        }
LABEL_79:
        if ( (v71 & 0x20) != 0 )
        {
          v73 = _mm_cvtsi32_si128((unsigned int)retaddr);
LABEL_83:
          *((float *)&v63[3].mNext + 1) = *((float *)&v63[3].mNext + 1) - _mm_cvtepi32_ps(v73).m128_f32[0];
          goto LABEL_84;
        }
        if ( (v71 & 0x10) != 0 )
        {
          v73 = _mm_cvtsi32_si128((int)retaddr / 2);
          goto LABEL_83;
        }
LABEL_84:
        Render::Font::Print(
          mData,
          this->mView,
          (int)*(float *)&v63[3].mNext,
          (int)*((float *)&v63[3].mNext + 1),
          (UFG::qColour *)&v63[2],
          (char *)v63[1].mPrev,
          colour_right);
LABEL_85:
        v62 = this->mDebugData;
        v63 = v63->mNext;
        if ( v63 == (UFG::qNode<Render::DebugText,Render::DebugText> *)&v62->mDebugTextLines )
          goto LABEL_86;
      }
      v72 = _mm_cvtsi32_si128(w);
LABEL_78:
      *(float *)&v63[3].mNext = *(float *)&v63[3].mNext - _mm_cvtepi32_ps(v72).m128_f32[0];
      goto LABEL_79;
    }
LABEL_86:
    for ( kk = this->mDebugData->mDebugIcons.mNode.mNext; kk != &this->mDebugData->mDebugIcons.mNode; kk = kk->mNext )
    {
      v75 = (int)*((float *)&kk[1].mNext + 1);
      v76 = (int)*(float *)&kk[2].mPrev;
      v77 = (unsigned int)kk[1].mPrev;
      v79 = *(UFG::qColour *)((char *)&kk[2] + 4);
      Render::View::DrawIcon(
        this->mView,
        v77,
        (int)*((float *)&kk[1].mPrev + 1),
        (int)*(float *)&kk[1].mNext,
        v75,
        v76,
        &v79,
        0xA3833FDE);
    }
    if ( (this->mFeatureFlags & 1) == 0 )
      Render::DebugDrawContext::Clear(this);
  }
}

// File Line: 1442
// RVA: 0x1A000
void __fastcall Render::DebugDrawManager::Init(Render::DebugDrawManager::InitInfo *init_info)
{
  Render::DebugDrawManager *v2; // rax

  v2 = (Render::DebugDrawManager *)UFG::qMalloc(0x10ui64, "DebugDrawManager", 0i64);
  if ( v2 )
  {
    v2->mContexts.mNode.mPrev = &v2->mContexts.mNode;
    v2->mContexts.mNode.mNext = &v2->mContexts.mNode;
  }
  Render::DebugDrawManager::mInstance = v2;
  Render::DebugDrawManager::CreateContext(v2, 0, init_info->mPersistentMainSize, 3u);
  Render::DebugDrawManager::CreateContext(
    Render::DebugDrawManager::mInstance,
    1u,
    init_info->mPersistentOverlaySize,
    1u);
  Render::DebugDrawManager::CreateContext(Render::DebugDrawManager::mInstance, 2u, init_info->mMainSize, 2u);
  Render::DebugDrawManager::CreateContext(Render::DebugDrawManager::mInstance, 3u, init_info->mOverlaySize, 0);
}

// File Line: 1463
// RVA: 0x19FD0
Render::DebugDrawManager *__fastcall Render::DebugDrawManager::GetContext(
        Render::DebugDrawManager *this,
        unsigned int uid)
{
  Render::DebugDrawManager *result; // rax

  result = (Render::DebugDrawManager *)this->mContexts.mNode.mNext;
  if ( result == this )
    return 0i64;
  while ( LODWORD(result[1].mContexts.mNode.mPrev) != uid )
  {
    result = (Render::DebugDrawManager *)result->mContexts.mNode.mNext;
    if ( result == this )
      return 0i64;
  }
  return result;
}

// File Line: 1478
// RVA: 0x17A80
UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *__fastcall Render::DebugDrawManager::CreateContext(
        Render::DebugDrawManager *this,
        unsigned int uid,
        unsigned int mem_size,
        unsigned int context_feature_flags)
{
  char *v8; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v9; // rbx
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v10; // rdi
  char *v11; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v12; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *mPrev; // rcx

  v8 = UFG::qMalloc(0x38ui64, "DebugDrawContext", 0i64);
  v9 = (UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *)v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = v8;
    *((_QWORD *)v8 + 1) = v8;
    *((_DWORD *)v8 + 4) = uid;
    *((_DWORD *)v8 + 5) = context_feature_flags;
    v10 = 0i64;
    *((_QWORD *)v8 + 3) = 0i64;
    *((_QWORD *)v8 + 4) = 0i64;
    *((_QWORD *)v8 + 5) = 0i64;
  }
  else
  {
    v10 = 0i64;
    v9 = 0i64;
  }
  v11 = UFG::qMalloc(0x200ui64, "ViewDebugContext.DebugData", 0x8000ui64);
  if ( v11 )
  {
    Render::DebugData::DebugData((Render::DebugData *)v11, mem_size);
    v10 = v12;
  }
  v9[2].mNext = v10;
  mPrev = this->mContexts.mNode.mPrev;
  mPrev->mNext = v9;
  v9->mPrev = mPrev;
  v9->mNext = &this->mContexts.mNode;
  this->mContexts.mNode.mPrev = v9;
  return v9;
}

// File Line: 1490
// RVA: 0x1A0B0
void __fastcall Render::DebugDrawManager::SetContextsTargetSize(
        Render::DebugDrawManager *this,
        int width,
        int height,
        unsigned int feature_mask,
        unsigned int feature_ref)
{
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *i; // rax

  for ( i = this->mContexts.mNode.mNext;
        i != (UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *)this;
        i = i->mNext )
  {
    if ( (feature_mask & HIDWORD(i[1].mPrev)) == feature_ref )
    {
      LODWORD(i[2].mPrev) = width;
      HIDWORD(i[2].mPrev) = height;
    }
  }
}

// File Line: 1503
// RVA: 0x19F60
void __fastcall Render::DebugDrawManager::FlushContexts(
        Render::DebugDrawManager *this,
        Render::View *view,
        unsigned int feature_mask,
        unsigned int feature_ref)
{
  Render::DebugDrawContext *i; // rbx

  for ( i = (Render::DebugDrawContext *)this->mContexts.mNode.mNext;
        i != (Render::DebugDrawContext *)this;
        i = (Render::DebugDrawContext *)i->mNext )
  {
    if ( (feature_mask & i->mFeatureFlags) == feature_ref )
    {
      i->mView = view;
      Render::DebugDrawContext::Flush(i);
      i->mView = 0i64;
    }
  }
}

// File Line: 1518
// RVA: 0x17910
void __fastcall Render::DebugDrawManager::ClearContexts(
        Render::DebugDrawManager *this,
        unsigned int feature_mask,
        unsigned int feature_ref)
{
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *i; // rbx
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *mNext; // rdx
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v8; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v9; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v10; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v11; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v12; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v13; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v14; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v15; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v16; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v17; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v18; // rax

  for ( i = this->mContexts.mNode.mNext;
        i != (UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *)this;
        i = i->mNext )
  {
    if ( (feature_mask & HIDWORD(i[1].mPrev)) == feature_ref )
    {
      mNext = i[2].mNext;
      if ( mNext )
      {
        UFG::qLinearAllocator::Init(
          (UFG::qLinearAllocator *)&mNext[16],
          (char *)mNext[13].mNext,
          LODWORD(mNext[24].mPrev),
          0i64,
          0i64);
        v8 = i[2].mNext + 7;
        v8->mPrev = v8;
        v8->mNext = v8;
        v9 = i[2].mNext + 5;
        v9->mPrev = v9;
        v9->mNext = v9;
        v10 = i[2].mNext + 6;
        v10->mPrev = v10;
        v10->mNext = v10;
        v11 = i[2].mNext + 3;
        v11->mPrev = v11;
        v11->mNext = v11;
        v12 = i[2].mNext + 8;
        v12->mPrev = v12;
        v12->mNext = v12;
        v13 = i[2].mNext + 9;
        v13->mPrev = v13;
        v13->mNext = v13;
        v14 = i[2].mNext + 10;
        v14->mPrev = v14;
        v14->mNext = v14;
        v15 = i[2].mNext + 11;
        v15->mPrev = v15;
        v15->mNext = v15;
        v16 = i[2].mNext + 12;
        v16->mPrev = v16;
        v16->mNext = v16;
        v17 = i[2].mNext + 2;
        v17->mPrev = v17;
        v17->mNext = v17;
        v18 = i[2].mNext + 4;
        v18->mPrev = v18;
        v18->mNext = v18;
        LODWORD(i[2].mNext[13].mPrev) = 0;
        UFG::qLinearAllocator::Reset((UFG::qLinearAllocator *)&i[2].mNext[16]);
      }
    }
  }
}

// File Line: 1536
// RVA: 0x1A0E0
void __fastcall Render::gXRayDrawCallback(
        Illusion::Material *material,
        Render::View *view,
        Illusion::StateValues *state_values,
        Illusion::Primitive *primitive)
{
  unsigned int v4; // esi
  _WORD *v5; // rdi
  __int64 mOffset; // rax
  _WORD *v10; // rax
  __int64 v11; // rax
  _WORD *v12; // rax
  __int64 v13; // rax
  _WORD *v14; // rax
  __int64 v15; // rax

  v4 = *(_DWORD *)&material[2].mDebugName[28];
  v5 = 0i64;
  if ( v4 != 1660426324 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&material[2].mDebugName[4],
      *((_DWORD *)&material[2].UFG::qResourceData + 22),
      0x62F81854u);
    mOffset = material->mMaterialUser.mOffset;
    if ( mOffset )
      v10 = (_WORD *)((char *)&material->mMaterialUser + mOffset);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
  }
  if ( material[2].mNode.mUID != -1551679522 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&material[2],
      (unsigned int)material[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0xA3833FDE);
    v11 = material->mMaterialUser.mOffset;
    if ( v11 )
      v12 = (_WORD *)((char *)&material->mMaterialUser + v11);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
  }
  Illusion::SubmitContext::Draw(view->mSubmitContext, primitive, material);
  if ( *(_DWORD *)&material[2].mDebugName[28] != v4 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&material[2].mDebugName[4],
      *((_DWORD *)&material[2].UFG::qResourceData + 22),
      v4);
    v13 = material->mMaterialUser.mOffset;
    if ( v13 )
      v14 = (_WORD *)((char *)&material->mMaterialUser + v13);
    else
      v14 = 0i64;
    *v14 |= 0x20u;
  }
  if ( material[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&material[2],
      (unsigned int)material[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v15 = material->mMaterialUser.mOffset;
    if ( v15 )
      v5 = (_WORD *)((char *)&material->mMaterialUser + v15);
    *v5 |= 0x20u;
  }
}

