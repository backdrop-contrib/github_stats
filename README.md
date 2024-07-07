# Github Stats

Get an overview of all projects you're maintainer of and keep an eye on
theirs statistics.

Information is automatically fetched via Github API (public).

Use case: if you maintain lots of projects on Github and want to keep an eye
on those.

So this module's probably only useful for a handful of people. It provides
no value for BackdropCMS users or admins.

Add projects via github-project/add, you have to add the project name and
the Github path. The rest gets fetched automatically.

There's an overview table on github-project/list.

Permissions aren't very fine grained. Adapt as needed on
admin/config/people/permissions#module-github_stats.

A cron job will keep infos up to date. There's no admin interface for
tweaks, but some modification's possible via settings.php.

## Installation

- Install this module using the official [Backdrop CMS instructions](https://docs.backdropcms.org/documentation/extend-with-modules)

## Issues

Bugs and feature requests should be reported in the [Issue Queue](https://github.com/backdrop-contrib/github_stats/issues)

## Current Maintainers

- [Indigoxela](https://github.com/indigoxela)
- Additional maintainers welcome

## License

This project is GPL v3 software. See the LICENSE.txt file in this directory for complete text.
