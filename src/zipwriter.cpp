/****************************************************************************
** Copyright (c) 2013 Debao Zhang <hello@debao.me>
** All right reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/
#include "zipwriter_p.h"
#include <QDebug>
#include <private/qzipwriter_p.h>

namespace QXlsx {

ZipWriter::ZipWriter(const QString &filePath, QObject *parent) :
    QObject(parent)
{
    m_writer = new QZipWriter(filePath, QIODevice::WriteOnly);
    m_writer->setCompressionPolicy(QZipWriter::NeverCompress);
}

ZipWriter::~ZipWriter()
{
    delete m_writer;
}

void ZipWriter::addFile(const QString &filePath, QIODevice *device)
{
    m_writer->addFile(filePath, device);
}

void ZipWriter::addFile(const QString &filePath, const QByteArray &data)
{
    qDebug()<<filePath<<data.size();
    m_writer->addFile(filePath, data);
}

void ZipWriter::close()
{
    m_writer->close();
}

} // namespace QXlsx
