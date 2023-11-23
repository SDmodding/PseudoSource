// File Line: 27
// RVA: 0xE70A00
hkProcess *__fastcall hkDebugDisplayProcess::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkDebugDisplayProcess *v2; // rax
  __int64 v3; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v2 = (hkDebugDisplayProcess *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 72i64);
  if ( v2 && (hkDebugDisplayProcess::hkDebugDisplayProcess(v2), v3) )
    return (hkProcess *)(v3 + 16);
  else
    return 0i64;
}

// File Line: 33
// RVA: 0xE70920
void __fastcall hkDebugDisplayProcess::hkDebugDisplayProcess(hkDebugDisplayProcess *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 1;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkDebugDisplayProcess::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkDebugDisplayProcess::`vftable{for `hkProcess};
  this->hkDebugDisplayHandler::vfptr = (hkDebugDisplayHandlerVtbl *)&hkDebugDisplayProcess::`vftable{for `hkDebugDisplayHandler};
  if ( !(_DWORD)hkDebugDisplayProcess::m_tag )
    hkDebugDisplayProcess::registerProcess();
  hkDebugDisplay::addDebugDisplayHandler(hkSingleton<hkDebugDisplay>::s_instance, &this->hkDebugDisplayHandler);
}

// File Line: 42
// RVA: 0xE70A50
void hkDebugDisplayProcess::registerProcess(void)
{
  LODWORD(hkDebugDisplayProcess::m_tag) = hkProcessFactory::registerProcess(
                                            hkSingleton<hkProcessFactory>::s_instance,
                                            "Debug Display",
                                            hkDebugDisplayProcess::create);
}

// File Line: 47
// RVA: 0xE70990
void __fastcall hkDebugDisplayProcess::~hkDebugDisplayProcess(hkDebugDisplayProcess *this)
{
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkDebugDisplayProcess::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkDebugDisplayProcess::`vftable{for `hkProcess};
  this->hkDebugDisplayHandler::vfptr = (hkDebugDisplayHandlerVtbl *)&hkDebugDisplayProcess::`vftable{for `hkDebugDisplayHandler};
  hkDebugDisplay::removeDebugDisplayHandler(hkSingleton<hkDebugDisplay>::s_instance, &this->hkDebugDisplayHandler);
  this->hkDebugDisplayHandler::vfptr = (hkDebugDisplayHandlerVtbl *)&hkDebugDisplayHandler::`vftable;
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkProcess::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 52
// RVA: 0xE70A80
hkResult *__fastcall hkDebugDisplayProcess::addGeometry(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkArrayBase<hkDisplayGeometry *> *geometries,
        hkTransformf *transform,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  (*(void (__fastcall **)(hkProcessHandler *, hkResult *, hkArrayBase<hkDisplayGeometry *> *, hkTransformf *, unsigned __int64, int, unsigned __int64, _DWORD))this[-1].m_processHandler->hkProcess::vfptr->gap8)(
    this[-1].m_processHandler,
    result,
    geometries,
    transform,
    id,
    tag,
    shapeIdHint,
    0);
  return result;
}

// File Line: 57
// RVA: 0xE70AD0
hkResult *__fastcall hkDebugDisplayProcess::addGeometryInstance(
        hkDebugDisplayProcess *this,
        hkResult *result,
        unsigned __int64 instID,
        hkTransformf *transform,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, unsigned __int64, hkTransformf *, unsigned __int64, int, unsigned __int64))this[-1].m_processHandler->hkProcess::vfptr->getProcessName)(
    this[-1].m_processHandler,
    result,
    instID,
    transform,
    id,
    tag,
    shapeIdHint);
  return result;
}

// File Line: 62
// RVA: 0xE70B20
hkResult *__fastcall hkDebugDisplayProcess::setGeometryPickable(
        hkDebugDisplayProcess *this,
        hkResult *result,
        __int64 isPickable,
        unsigned __int64 id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, __int64, unsigned __int64, int))this[-1].m_processHandler->hkProcess::vfptr->getProcessByName)(
    this[-1].m_processHandler,
    result,
    isPickable,
    id,
    tag);
  return result;
}

// File Line: 68
// RVA: 0xE71020
hkResult *__fastcall hkDebugDisplayProcess::displayGeometry(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkArrayBase<hkDisplayGeometry *> *geometries,
        hkTransformf *transform,
        unsigned int color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkArrayBase<hkDisplayGeometry *> *, hkTransformf *, unsigned int, int, int))this[-1].m_processHandler->hkProcess::vfptr[3].__vecDelDtor)(
    this[-1].m_processHandler,
    result,
    geometries,
    transform,
    color,
    id,
    tag);
  return result;
}

// File Line: 73
// RVA: 0xE71070
hkResult *__fastcall hkDebugDisplayProcess::displayGeometry(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkArrayBase<hkDisplayGeometry *> *geometries,
        __int64 color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkArrayBase<hkDisplayGeometry *> *, __int64, int, int))this[-1].m_processHandler->hkProcess::vfptr[2].deleteProcess)(
    this[-1].m_processHandler,
    result,
    geometries,
    color,
    id,
    tag);
  return result;
}

// File Line: 78
// RVA: 0xE70B50
hkResult *__fastcall hkDebugDisplayProcess::setGeometryVisibility(
        hkDebugDisplayProcess *this,
        hkResult *result,
        __int64 geometryIndex,
        __int64 isVisible,
        unsigned __int64 id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, __int64, __int64, unsigned __int64, int))this[-1].m_processHandler->hkProcess::vfptr->getProcessesByType)(
    this[-1].m_processHandler,
    result,
    geometryIndex,
    isVisible,
    id,
    tag);
  return result;
}

// File Line: 83
// RVA: 0xE70B90
hkResult *__fastcall hkDebugDisplayProcess::setGeometryColor(
        hkDebugDisplayProcess *this,
        hkResult *result,
        __int64 color,
        unsigned __int64 id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, __int64, unsigned __int64, int))this[-1].m_processHandler->hkProcess::vfptr->selectProcess)(
    this[-1].m_processHandler,
    result,
    color,
    id,
    tag);
  return result;
}

// File Line: 88
// RVA: 0xE70BC0
hkResult *__fastcall hkDebugDisplayProcess::setGeometryTransparency(
        hkDebugDisplayProcess *this,
        hkResult *result,
        float alpha,
        unsigned __int64 id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkProcessHandlerVtbl *, unsigned __int64, int))this[-1].m_processHandler->hkProcess::vfptr->createProcess)(
    this[-1].m_processHandler,
    result,
    this[-1].m_processHandler->hkProcess::vfptr,
    id,
    tag);
  return result;
}

// File Line: 93
// RVA: 0xE70BF0
hkResult *__fastcall hkDebugDisplayProcess::updateGeometry(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkTransformf *transform,
        unsigned __int64 id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkTransformf *, unsigned __int64, int))this[-1].m_processHandler->hkProcess::vfptr[1].__vecDelDtor)(
    this[-1].m_processHandler,
    result,
    transform,
    id,
    tag);
  return result;
}

// File Line: 98
// RVA: 0xE70C20
hkResult *__fastcall hkDebugDisplayProcess::updateGeometry(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkMatrix4f *transform,
        unsigned __int64 id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkMatrix4f *, unsigned __int64, int))this[-1].m_processHandler->hkProcess::vfptr->deleteProcess)(
    this[-1].m_processHandler,
    result,
    transform,
    id,
    tag);
  return result;
}

// File Line: 103
// RVA: 0xE70C50
hkResult *__fastcall hkDebugDisplayProcess::skinGeometry(
        hkDebugDisplayProcess *this,
        hkResult *result,
        unsigned __int64 *ids,
        __int64 numIds,
        hkMatrix4f *poseModel,
        int numPoseModel,
        hkMatrix4f *worldFromModel,
        int tag)
{
  (*(void (__fastcall **)(hkProcessHandler *, hkResult *, unsigned __int64 *, __int64, hkMatrix4f *, int, hkMatrix4f *, int))this[-1].m_processHandler->hkProcess::vfptr[1].gap8)(
    this[-1].m_processHandler,
    result,
    ids,
    numIds,
    poseModel,
    numPoseModel,
    worldFromModel,
    tag);
  return result;
}

// File Line: 108
// RVA: 0xE70CA0
hkResult *__fastcall hkDebugDisplayProcess::removeGeometry(
        hkDebugDisplayProcess *this,
        hkResult *result,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, unsigned __int64, _QWORD, unsigned __int64))this[-1].m_processHandler->hkProcess::vfptr[1].getProcessByName)(
    this[-1].m_processHandler,
    result,
    id,
    (unsigned int)hkDebugDisplayProcess::m_tag,
    shapeIdHint);
  return result;
}

// File Line: 113
// RVA: 0xE70CE0
hkResult *__fastcall hkDebugDisplayProcess::updateCamera(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkVector4f *from,
        hkVector4f *to,
        hkVector4f *up,
        float nearPlane,
        float farPlane,
        float fov,
        const char *name)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkVector4f *, hkVector4f *, hkVector4f *, _DWORD, _DWORD, _DWORD, const char *))this[-1].m_processHandler->hkProcess::vfptr[1].getProcessesByType)(
    this[-1].m_processHandler,
    result,
    from,
    to,
    up,
    LODWORD(nearPlane),
    LODWORD(farPlane),
    LODWORD(fov),
    name);
  return result;
}

// File Line: 118
// RVA: 0xE70D50
hkResult *__fastcall hkDebugDisplayProcess::displayPoint(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkVector4f *position,
        __int64 color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkVector4f *, __int64, int, int))this[-1].m_processHandler->hkProcess::vfptr[1].selectProcess)(
    this[-1].m_processHandler,
    result,
    position,
    color,
    id,
    tag);
  return result;
}

// File Line: 123
// RVA: 0xE70D90
hkResult *__fastcall hkDebugDisplayProcess::displayLine(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkVector4f *start,
        hkVector4f *end,
        unsigned int color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkVector4f *, hkVector4f *, unsigned int, int, int))this[-1].m_processHandler->hkProcess::vfptr[1].createProcess)(
    this[-1].m_processHandler,
    result,
    start,
    end,
    color,
    id,
    tag);
  return result;
}

// File Line: 128
// RVA: 0xE70DE0
hkResult *__fastcall hkDebugDisplayProcess::displayTriangle(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        unsigned int color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkVector4f *, hkVector4f *, hkVector4f *, unsigned int, int, int))this[-1].m_processHandler->hkProcess::vfptr[1].deleteProcess)(
    this[-1].m_processHandler,
    result,
    a,
    b,
    c,
    color,
    id,
    tag);
  return result;
}

// File Line: 133
// RVA: 0xE70E30
hkResult *__fastcall hkDebugDisplayProcess::displayPoint2d(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkVector4f *position,
        __int64 color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkVector4f *, __int64, int, int))this[-1].m_processHandler->hkProcess::vfptr[2].getProcessId)(
    this[-1].m_processHandler,
    result,
    position,
    color,
    id,
    tag);
  return result;
}

// File Line: 138
// RVA: 0xE70E70
hkResult *__fastcall hkDebugDisplayProcess::displayLine2d(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkVector4f *start,
        hkVector4f *end,
        unsigned int color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkVector4f *, hkVector4f *, unsigned int, int, int))this[-1].m_processHandler->hkProcess::vfptr[2].getProcessName)(
    this[-1].m_processHandler,
    result,
    start,
    end,
    color,
    id,
    tag);
  return result;
}

// File Line: 143
// RVA: 0xE70EC0
hkResult *__fastcall hkDebugDisplayProcess::displayTriangle2d(
        hkDebugDisplayProcess *this,
        hkResult *result,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        unsigned int color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, hkVector4f *, hkVector4f *, hkVector4f *, unsigned int, int, int))this[-1].m_processHandler->hkProcess::vfptr[2].getProcessByName)(
    this[-1].m_processHandler,
    result,
    a,
    b,
    c,
    color,
    id,
    tag);
  return result;
}

// File Line: 148
// RVA: 0xE70F10
hkResult *__fastcall hkDebugDisplayProcess::displayText2d(
        hkDebugDisplayProcess *this,
        hkResult *result,
        const char *text,
        hkVector4f *pos,
        float sizeScale,
        unsigned int color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, const char *, hkVector4f *, _DWORD, unsigned int, int, int))this[-1].m_processHandler->hkProcess::vfptr[2].getProcessesByType)(
    this[-1].m_processHandler,
    result,
    text,
    pos,
    LODWORD(sizeScale),
    color,
    id,
    tag);
  return result;
}

// File Line: 153
// RVA: 0xE70F60
hkResult *__fastcall hkDebugDisplayProcess::displayText(
        hkDebugDisplayProcess *this,
        hkResult *result,
        const char *text,
        __int64 color,
        int id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, const char *, __int64, int, int))this[-1].m_processHandler->hkProcess::vfptr[2].__vecDelDtor)(
    this[-1].m_processHandler,
    result,
    text,
    color,
    id,
    tag);
  return result;
}

// File Line: 158
// RVA: 0xE70FA0
hkResult *__fastcall hkDebugDisplayProcess::display3dText(
        hkDebugDisplayProcess *this,
        hkResult *result,
        const char *text,
        hkVector4f *pos,
        unsigned int color,
        int id,
        int tag)
{
  (*(void (__fastcall **)(hkProcessHandler *, hkResult *, const char *, hkVector4f *, unsigned int, int, int))this[-1].m_processHandler->hkProcess::vfptr[2].gap8)(
    this[-1].m_processHandler,
    result,
    text,
    pos,
    color,
    id,
    tag);
  return result;
}

// File Line: 163
// RVA: 0xE70FF0
hkResult *__fastcall hkDebugDisplayProcess::displayAnnotation(
        hkDebugDisplayProcess *this,
        hkResult *result,
        const char *text,
        __int64 id,
        int tag)
{
  ((void (__fastcall *)(hkProcessHandler *, hkResult *, const char *, __int64, int))this[-1].m_processHandler->hkProcess::vfptr[2].selectProcess)(
    this[-1].m_processHandler,
    result,
    text,
    id,
    tag);
  return result;
}

// File Line: 168
// RVA: 0xE710B0
hkResult *__fastcall hkDebugDisplayProcess::sendMemStatsDump(
        hkDebugDisplayProcess *this,
        hkResult *result,
        const char *data,
        __int64 length)
{
  (*(void (__fastcall **)(hkProcessHandler *, hkResult *, const char *, __int64))this[-1].m_processHandler->hkProcess::vfptr[3].gap8)(
    this[-1].m_processHandler,
    result,
    data,
    length);
  return result;
}

// File Line: 173
// RVA: 0xE710E0
hkResult *__fastcall hkDebugDisplayProcess::holdImmediate(hkDebugDisplayProcess *this, hkResult *result)
{
  ((void (__fastcall *)(hkProcessHandler *))this[-1].m_processHandler->hkProcess::vfptr[3].getProcessId)(this[-1].m_processHandler);
  return result;
}

