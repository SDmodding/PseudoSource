// File Line: 38
// RVA: 0xE4CE00
hkBool *__fastcall hkSubStreamWriter::isOk(hkReplayStreamReader *this, hkBool *result)
{
  this->m_stream->vfptr[1].__first_virtual_table_function__(this->m_stream);
  return result;
}

// File Line: 53
// RVA: 0xE4CE50
hkBool *__fastcall hkSubStreamWriter::seekTellSupported(hkSubStreamWriter *this, hkBool *result)
{
  ((void (__fastcall *)(hkStreamWriter *))this->m_childStream->vfptr[3].__vecDelDtor)(this->m_childStream);
  return result;
}

// File Line: 58
// RVA: 0xE4CE20
hkResult *__fastcall hkSubStreamWriter::seek(
        hkSubStreamWriter *this,
        hkResult *result,
        __int64 offset,
        hkStreamWriter::SeekWhence whence)
{
  if ( whence == STREAM_NULL )
    offset = (unsigned int)(this->m_startOffset + offset);
  ((void (__fastcall *)(hkStreamWriter *, hkResult *, __int64))this->m_childStream->vfptr[3].__first_virtual_table_function__)(
    this->m_childStream,
    result,
    offset);
  return result;
}

// File Line: 67
// RVA: 0xE4CE70
__int64 __fastcall hkSubStreamWriter::tell(hkSubStreamWriter *this)
{
  return ((unsigned int (__fastcall *)(hkStreamWriter *))this->m_childStream->vfptr[4].__vecDelDtor)(this->m_childStream)
       - this->m_startOffset;
}

