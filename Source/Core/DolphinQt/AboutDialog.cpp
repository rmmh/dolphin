// Copyright 2014 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#include <memory>
#include <QDesktopServices>
#include <QUrl>

#include "ui_AboutDialog.h"

#include "Common/Common.h"

#include "DolphinQt/AboutDialog.h"
#include "DolphinQt/Utils/Resources.h"

DAboutDialog::DAboutDialog(QWidget* parent_widget)
	: QDialog(parent_widget)
{
	setWindowModality(Qt::WindowModal);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

	m_ui = std::make_unique<Ui::DAboutDialog>();
	m_ui->setupUi(this);
	m_ui->lblGitRev->setText(QString::fromUtf8(scm_desc_str));
	m_ui->lblGitInfo->setText(m_ui->lblGitInfo->text().arg(QString::fromUtf8(scm_branch_str),
		QString::fromUtf8(scm_rev_git_str)));
	m_ui->lblFinePrint->setText(m_ui->lblFinePrint->text().arg(QStringLiteral("2015")));
	m_ui->lblLicenseAuthorsSupport->setText(m_ui->lblLicenseAuthorsSupport->text()
		.arg(QStringLiteral("https://github.com/dolphin-emu/dolphin/blob/master/license.txt"))
		.arg(QStringLiteral("https://github.com/dolphin-emu/dolphin/graphs/contributors"))
		.arg(QStringLiteral("https://forums.dolphin-emu.org/")));
	m_ui->lblLogo->setPixmap(Resources::GetPixmap(Resources::DOLPHIN_LOGO_LARGE));
}

DAboutDialog::~DAboutDialog()
{
}
