#ifndef FILEZILLA_ENGINE_STORJ_RESOLVE_HEADER
#define FILEZILLA_ENGINE_STORJ_RESOLVE_HEADER

#include "storjcontrolsocket.h"

class CStorjResolveOpData final : public COpData, public CStorjOpData
{
public:
	CStorjResolveOpData(CStorjControlSocket & controlSocket, CServerPath const& path, std::wstring const& file, std::wstring & bucket, std::wstring * fileId, bool ignore_missing_file)
		: COpData(PrivCommand::resolve)
		, CStorjOpData(controlSocket)
		, path_(path)
		, file_(file)
		, bucket_(bucket)
		, fileId_(fileId)
		, ignore_missing_file_(ignore_missing_file)
	{
	}

	virtual int Send() override;
	virtual int ParseResponse() override;
	virtual int SubcommandResult(int prevResult, COpData const& previousOperation) override;

private:
	CServerPath const path_;
	std::wstring const file_;

	std::wstring & bucket_;
	std::wstring * const fileId_;
	bool ignore_missing_file_{};
};
#endif
