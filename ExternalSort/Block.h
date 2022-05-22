#pragma once

#include "Serializable.h"
#include "Record.h"

/// <summary>
/// ��¼�飬��Ӧһ���ڴ��
/// </summary>
class Block :public Serializable
{
public:
    /// <summary>
    /// ����һ����¼��
    /// </summary>
    /// <param name="size">���еļ�¼����</param>
    Block(const size_t size);

    ~Block();

    /// <summary>
    /// �����ж����¼�飬���ض��������
    /// </summary>
    /// <param name="stream">������</param>
    /// <returns>�����¼�ĸ���</returns>
    virtual int load(std::istream& stream) override;

    /// <summary>
    /// ����ǰ��¼�����������
    /// </summary>
    /// <param name="stream">�����</param>
    /// <returns>����ɹ�����0��ʧ�ܷ���-1</returns>
    virtual int dump(std::ostream& stream) override;
    
private:
    const size_t m_size;
    Record* m_record_array;
};
