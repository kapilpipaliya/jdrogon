#ifndef MODELENUMS_H
#define MODELENUMS_H

#include <QHashFunctions>
#include <qnamespace.h>
#include <QMetaType>

namespace eAccessory {
enum class Column {
    Id,
    MaterialId,
    Rank,
    Slug,
    Name,
    CreateUserId,
    UpdateUserId,
    InsertedAt,
    UpdatedAt
};

inline uint qHash(const Column key, uint seed) { return ::qHash(static_cast<uint>(key), seed); }

enum class Role {
    ID = Qt::UserRole,                     /**< The account id is stored in this role in column 0 as a string.*/
    Favorite = Qt::UserRole + 1,           /**< The 'account is favorite' property is stored in this role in column 0 as a bool.*/
    Account = Qt::UserRole + 2,            /**< The MyMoneyAccount is stored in this role in column 0.*/
    Balance = Qt::UserRole + 3,            /**< The account balance is stored in this role in column 0 as a MyMoneyMoney object.*/
    Value = Qt::UserRole + 4,              /**< The account value (the balance converted to base currency) is stored in this role in column 0 as a MyMoneyMoney object.*/
    TotalValue = Qt::UserRole + 5,         /**< The account total value (the value of the account and of child accounts) is stored in this role in column 0 as a MyMoneyMoney object.*/
    DisplayOrder = Qt::UserRole + 9,       /**< This role is used by the filtering proxies to order the accounts for displaying.*/
    FullName = Qt::UserRole + 10,          /**< This role is used to provide the full pathname of the account */
};

inline uint qHash(const Role key, uint seed) { return ::qHash(static_cast<uint>(key), seed); }
}

namespace eLedgerModel {
enum class Column {
    Number = 0,
    Date,
    Security,
    CostCenter,
    Detail,
    Reconciliation,
    Payment,
    Deposit,
    Quantity,
    Price,
    Amount,
    Value,
    Balance,

    // insert new columns above this line
    LastColumn
};

enum class Role {
    // Roles returning values
    PostDate = Qt::UserRole,
    PayeeName,
    Account,
    CounterAccount,
    SplitCount,
    Reconciliation,
    ReconciliationShort,
    ReconciliationLong,
    SplitShares,
    ShareAmount,
    ShareAmountSuffix,
    SplitValue,
    Memo,
    SingleLineMemo,
    Number,
    Erroneous,
    Import,
    Split,
    Transaction,

    // Roles returning ids
    TransactionId,
    SplitId,
    TransactionSplitId,
    PayeeId,
    AccountId,
    CounterAccountId,
    CostCenterId,
    ScheduleId,
    TransactionCommodity,

    // A pseudo role to emit the dataChanged() signal when
    // used with setData()
    EmitDataChanged

};
}

/**
  * Make it possible to hold eAccountsModel::Column objects inside @ref QVariant objects.
  */
Q_DECLARE_METATYPE(eAccessory::Column)

#endif // MODELENUMS_H
